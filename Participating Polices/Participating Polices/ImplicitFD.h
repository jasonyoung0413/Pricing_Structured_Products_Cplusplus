#pragma once
#include "ParticipatingPolices.h"

class ImplicitFD{
public:
  ParticipatingPolices* product;
  int max_i,max_j;
  double delta_a, delta_p;
  double delta_s = 1 / max_k;
  double** value, ** value_sur;
  ImplicitFD(ParticipatingPolices* p,int i,int j):
      product(p),max_i(i),max_j(j){
	  delta_a = a_bar / i;
	  delta_p = p_bar / j;
  }
  void terPayoff();
  void backwardEval();
private:
  int a_bar = 1000, p_bar = 2000;
  // the number of time steps per year is fixed at 100.
  int max_k=100;
  double** last_value, ** last_value_sur;
};