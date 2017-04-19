#include "TrinomialLattice.h"
#include <math.h>
#include <iostream>
using namespace std;


TrinomialLattice::TrinomialLattice(Warrant* pWar, int nsteps, int n, GridFunc gridFunc, PayOffFunc payF) :
	warrant(pWar), steps(nsteps), numberOfYear(n), gridF(gridFunc), payOffF(payF) {
    //initilize;
	dt = warrant->maturity / nsteps;
	discount = exp(-warrant->rate*dt);
	days_step = int(n / (nsteps / warrant->maturity));
	max_k = int(numberOfYear / (4*days_step));
	//prob
	double lambda = sqrt(3);
	double dao_lambda = 1 / pow(lambda,2);
	double element1, element2;
	element1 = sqrt(dt)*(warrant->rate - pow((warrant->vol_wal),2)) / (lambda*warrant->vol_wal);
	element2 = sqrt(dt)*(warrant->rate - pow((warrant->vol_intel),2)) / (lambda*warrant->vol_intel);
	triprob[0] = ((1 + warrant->corr)*dao_lambda + element1 + element2) / 4;
	triprob[1] = ((1 - warrant->corr)*dao_lambda + element1 - element2) / 4;
	triprob[2] = ((1 + warrant->corr)*dao_lambda - element1 - element2) / 4;
	triprob[3] = ((1 - warrant->corr)*dao_lambda - element1 + element2) / 4;
	triprob[4] = 1 - dao_lambda;
	//lnprice step
	v1 = lambda * warrant->vol_wal * sqrt(dt);
	v2 = lambda * warrant->vol_intel * sqrt(dt);
}


double***
TrinomialLattice::initVal(int num_k) {
	double ***p;
	int num = steps;
	p = new double**[2 * num + 1];
	for (int i = 0; i <= (2 * num); i++) {
		p[i] = new double*[2 * num + 1];
	}
	for (int i = 0; i <= (2 * num); i++) {
		for (int j = 0; j <= (2 * num); j++) {
			p[i][j] = new double[num_k + 1];
		}
	}
	return p;
}


void
TrinomialLattice::terPayoff_FSG() {
	//initalize the matrix
	war_value = initVal(max_k);
	for (int i = 0; i <= (2 * steps); i++) {
		for (int j = 0; j <= (2 * steps); j++) {
			for (int k = 0; k <= max_k; k++) {
				war_value[i][j][k] = payOffF(warrant->wal_price*exp((i - steps)*v1),
					warrant->wal_exe_price, warrant->intel_price*exp((j - steps)*v2),
					warrant->intel_exe_price) +
					k*(warrant->coupon) / max_k;
			}
		}
	}
}


void
TrinomialLattice::delMem(double*** p) {
	for (int i = 0; i <= (2 * steps); i++) {
		for (int j = 0; j <= (2 * steps); j++) {
			delete[] p[i][j];
		}
	}
	for (int i = 0; i <= (2 * steps); i++)
		delete[]p[i];
	delete[]p;
}


void
TrinomialLattice::backwardEval_FSG() {
//	cout << warrant->call_right;
	int N = steps-1;
	while (N >= 0) {
	    last_war_value = war_value;
		int n = N % max_k;
		int num_k = n;
//		cout << n << endl;
		if (n == 0 && N != 0) {
			// at coupon date
			num_k = max_k;
		}
		// calculate the value
		war_value = initVal(num_k);
		for (int i = steps-N; i <= (steps + N); i++) {
			for (int j = steps-N; j <= (steps + N); j++) {
				for (int k = 0; k <= num_k; k++) {
					int i_now = i - steps, j_now = j - steps;
					int k_now = k;
					if (n == 0 && N != 0) {
						k_now = 0;
					}
					war_value[i][j][k] = discount*(
						triprob[0] * last_war_value[i + 1][j + 1][
							gridF(exp((i_now + 1)*v1), 0.87, exp((j_now + 1)*v2), 0.87, k_now)] +
						triprob[1] * last_war_value[i + 1][j - 1][
							gridF(exp((i_now + 1)*v1), 0.87, exp((j_now - 1)*v2), 0.87, k_now)] +
								triprob[2] * last_war_value[i - 1][j - 1][
									gridF(exp((i_now - 1)*v1), 0.87, exp((j_now - 1)*v2), 0.87, k_now)] +
								triprob[3] * last_war_value[i - 1][j + 1][
									gridF(exp((i_now - 1)*v1), 0.87, exp((j_now + 1)*v2), 0.87, k_now)] +
										triprob[4] * last_war_value[i][j][
											gridF(exp((i_now)*v1), 0.87, exp((j_now)*v2), 0.87, k_now)]
										);
					// at coupon date
					if (n == 0 && N != 0) {					
						// jump at the warrant value
						war_value[i][j][k] += k*(warrant->coupon) / max_k;
						// call right
//						if (k==0)
//						cout << i_now<<" "<<j_now << endl;
						if (warrant->call_right && (MIN(exp(i_now*v1), exp(j_now*v2)) > 0.87))
						{
//							cout << "here" << endl;
//							cout << war_value[i][j][k] << endl;
							war_value[i][j][k] = MIN(war_value[i][j][k], warrant->call_price);
						}
						
					}
				}
			}
		}
		// delete the last warrant value matrix
		delMem(last_war_value);
		N--;
	}
}