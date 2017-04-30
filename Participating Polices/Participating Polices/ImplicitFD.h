#pragma once
#include "ParticipatingPolices.h"

class ImplicitFD{
public:
  ParticipatingPolices* product;
  int max_i,max_j;
  double** value;
  ImplicitFD(ParticipatingPolices p,int i,int j):
      product(p),max_i(i),max_j(j){
  }
  void terPayoff();
  void backwardEval();
  void delMem(double** p);
private:
  double ** initVal();
  // the number of time steps per year is fixed at 100.
  int max_k=100;
  double** last_value;
}
