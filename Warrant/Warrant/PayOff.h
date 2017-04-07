#pragma once
#ifndef PAYOFF_H
#define PAYOFF_H
#include "Warrant.h"

int gridFunc(double s1, double e1, double s2, double e2, int k) {
	return k + ((MIN(s1 / e1, s2 / e2) > 1) ? 1 : 0);
}

double payOffFunc(double s1, double e1, double s2, double e2) {
	return 1 - MAX(1 - MIN(s1 / e1, s2 / e2), 0);
}
#endif