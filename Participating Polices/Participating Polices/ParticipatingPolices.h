#pragma once
#ifndef PARTICIPATINGPLICES_H
#define PARTICIPATINGPLICES_H

#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))

class ParticipatingPlices{
public:
  double principle;
  double rg;
  double alpha;
  double gamma;
  ParticipatingPlices(double p,double r,double a,double g)
  :principle(p), rg(r), alpha(a),gamma(g){
  }
};

#endif
