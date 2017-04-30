#include "ImplicitFD.h"
#include <math.h>
#include <iostream>

using namespace std;

double**
initVal_2d(int max_j,int max_i){
  double **p;
  p = new double* [max_j+1];
  for (int j = 0; j <= max_j; j++) {
	  p[j] = new double[max_i + 1];
  }
  return p;
}

void
delMem_2d(double** p, int max_j){
  for (int i=0;i<=max_j;i++){
    delete[] p[i];
  }
  delete[]p;
}

void
ImplicitFD::backwardEval() {
  for (int s=product->T; s>0; s--){
    // no-jump condition at the end of year
    if (s!=product->T){
      // consideration for k==0
		// European style

		// Surrender option 
		if (product->surrender) {
			// PSOR

			// surrender value
			product->surrender_value[s - 1] = value_sur[0][0] - value[0][0];
		}

    }
    // from the end of year s to the start of year s
	for (int k = 1; k <= max_k; k++) {
      // at the kth time step of year s.
      last_value = value;
	  for (int j = 0; j <= max_j; j++) {
		  value = initVal_2d(max_j, max_i);
		  value[j][0] = (1 - product->interest_rate*delta_s)*last_value[j][0];
		  // matrix of coefficient
		  double** coef;
		  coef = initVal_2d(max_i - 1, 4);
		  for (int i = 1; i < max_i; i++ ) {
			  double temp = pow(product->sigma*i, 2);
			  coef[i][1] = (product->interest_rate*i - temp)*delta_s / 2;
			  coef[i][2] = 1 + delta_s*(product->interest_rate + temp);
			  coef[i][3] = (- product->interest_rate*i - temp)*delta_s / 2;
			  coef[i][4] = last_value[j][i];
			  if (i == 1) {
				  coef[i][4] -= coef[i][1] * (1 - product->interest_rate*delta_s)*last_value[j][0];
				  coef[i][1] = 0;
			  }
			  if (i == max_i - 1) {
				 coef[i][3] += 2 * coef[i][2];
				 coef[i][2] = coef[i][1] - coef[i][2];
				 coef[i][1] = 0;
			  }
		  }
		  value[j] = Thomas(last_value[j]);
		  value[j][max_i] = 2 * value[j][max_i - 1] - value[j][max_i - 2];
	  }
	  delMem_2d(last_value, max_j);
    }
  }
}

double *
Thomas(double* last_v) {

}
