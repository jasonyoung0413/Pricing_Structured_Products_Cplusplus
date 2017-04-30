#pragma once
#ifndef PARTICIPATINGPOLICES_H
#define PARTICIPATINGPOLICES_H

#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))

class ParticipatingPolices{
public:
  double book_value,market_value;
  double interest_rate;
  double guaranteed_rate;
  double alpha,gamma;
  int T; // the number of years
  double* surrender_value;
  ParticipatingPolices(double P0,double A0,double r,double rg,
    double a,double g,int m)
  :book_value(P0),market_value(A0),interest_rate(r),
  guaranteed_rate(rg), alpha(a),gamma(g),T(m){
    surrender_value = new double(T);
  }
};

#endif
