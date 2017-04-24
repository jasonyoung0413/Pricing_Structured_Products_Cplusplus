#include "TrinomialLattice.h"
#include <math.h>
#include <iostream>
using namespace std;


void
TrinomialLattice::backwardEval_noFSG() {
	int N = steps - 1;
	while (N >= 0) {
//		cout << N << endl;
		last_war_value = war_value;
		int n = N % max_k;
		// calculate the value
		war_value = initVal(0);
		for (int i = steps - N; i <= (steps + N); i++) {
			for (int j = steps - N; j <= (steps + N); j++) {
				int i_now = i - steps, j_now = j - steps;
				war_value[i][j][0] = discount*(
					triprob[0] * last_war_value[i + 1][j + 1][0]+
						triprob[1] * last_war_value[i + 1][j - 1][0] +
							triprob[2] * last_war_value[i - 1][j - 1][0] +
								triprob[3] * last_war_value[i - 1][j + 1][0] +
									triprob[4] * last_war_value[i][j][0]);
				// PV of interest received for sure at next coupon date
				if (MIN(exp(i_now*v1), exp(j_now*v2)) >= 0.87 && N != 0) {
					war_value[i][j][0] += pow(discount, (max_k - n) % max_k)*(warrant->coupon) / max_k;
//					cout << "noFSG" << endl;
				}
					
			}
		}
		// delete the last warrant value matrix
		delMem(last_war_value);
		N--;
	}
}


void 
TrinomialLattice::terPayoff_noFSG() {
	//initalize the matrix
	war_value = initVal(0);
	for (int i = 0; i <= (2 * steps); i++) {
		for (int j = 0; j <= (2 * steps); j++) {
			int i_now = i - steps, j_now = j - steps;
			war_value[i][j][0] = payOffF(warrant->wal_price*exp((i - steps)*v1),
				warrant->wal_exe_price, warrant->intel_price*exp((j - steps)*v2),
				warrant->intel_exe_price);
			if (MIN(exp(i_now * v1), exp(j_now * v2)) > 0.87)
				war_value[i][j][0] += (warrant->coupon) / max_k;
		}
	}

}