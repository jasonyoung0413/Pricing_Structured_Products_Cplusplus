#include "ImplicitFD.h"
#include <math.h>
#include <iostream>
#include "PayOff.h"

using namespace std;

void
ImplicitFD::terPayoff() {
	for (int j = 0; j <= max_j; j++) {
		for (int i = 0; i <= max_i; i++) {
			    value[j][i] = payOffFunc(j, product->guaranteed_rate, i, product->gamma, product->alpha, delta_a, delta_p);
			if(product->surrender)
				value_sur[j][i] = payOffFunc(j, product->guaranteed_rate, i, product->gamma, product->alpha, delta_a, delta_p);
		}
	}
}