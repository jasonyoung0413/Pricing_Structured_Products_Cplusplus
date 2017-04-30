#include "ImplicitFD.h"
#include <math.h>
#include <iostream>

using namespace std;

double**
ImplicitFD::initVal(){
  double **p;
  p = new double* [max_i+1];
  for (int i = 0; i <= max_i; i++) {
	  p[i] = new double[max_j + 1];
  }
  return p;
}

void
ImplicitFD::delMem(double** p){
  for (int i=0;i<=max_i;i++){
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
			product->surrender_value[s - 1];
		}

    }
    // from the end of year s to the start of year s
	for (int k = 1; k <= max_k; k++) {
      // at the kth time step of year s.
      last_value = value;
	  for (int i = 0; i <= max_i; i++) {
		  value[i] = 
	  }
      delMem(last_value);
    }
  }
}
