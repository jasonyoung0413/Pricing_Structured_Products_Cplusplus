#pragma once
#ifndef TRINOMIALPRICE_H
#define TRINOMIALPRICE_H

#include "Tree.h"
#include "Warrant.h"

typedef int(*GridFunc) (double, double, double, double, int);
typedef double(*PayOffFunc) (double, double, double, double);

class TrinomialPrice {
public:
	Warrant* warrant;
	int steps;
	Tree* tree;
	TrinomialPrice(Warrant* pWar, int nsteps, GridFunc gridFunc, PayOffFunc payF);

	void buildTree(TreeNode *node, int nFromLeafNode);
	void backwardEval(TreeNode *node);
	void printTree(TreeNode *node);
private:
	double dt;
	double v1,v2;
	double triprob[5];
	double discount;
	GridFunc gridF;
	PayOffFunc payOffF;

};
#endif