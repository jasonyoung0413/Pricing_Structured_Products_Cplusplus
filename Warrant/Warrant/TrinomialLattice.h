#pragma once
#ifndef TRINOMIALLATTICE_H
#define TRINOMIALLATTICE_H
#include "Warrant.h"

typedef int(*GridFunc) (double, double, double, double, int);
typedef double(*PayOffFunc) (double, double, double, double);

class TrinomialLattice {
public:
	Warrant* warrant;
	int steps;
	double ***war_value;
    int numberOfYear;
	TrinomialLattice(Warrant* pWar, int nsteps, int n, GridFunc gridFunc, PayOffFunc payF);
	void terPayoff_FSG();
    void backwardEval_FSG();
	void terPayoff_noFSG();
	void backwardEval_noFSG();
	double triprob[5];
	void delMem(double*** p);
private:
	double*** initVal(int num_k);
	double dt;
	double v1,v2;
	double discount;
	double ***last_war_value;
	int max_k; 
	int days_step;
	GridFunc gridF;
	PayOffFunc payOffF;


};
#endif