#ifndef PAYOFF_H
#define PAYOFF_H

double payOffFunc(int j, double rG, int i, double gamma, double alpha, double delta_a, double delta_p){
	double jtilta;
	jtilta = j + MAX(j * rG, alpha * ((i * delta_a / delta_p - j) - j * gamma));
	return jtilta;
}

#endif
