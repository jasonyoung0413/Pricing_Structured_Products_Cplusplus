#include "TrinomialLattice.h"
#include "PayOff.h"
#include <iostream>

using namespace std;

int main() {
	//start our programming;
	double wal_price, intel_price, wal_vol, intel_vol, rou;
	double rate,coupon;
	//cout << "input variables: " << endl;
	//cin >> wal_price;
	//cin >> intel_price;

	// for example:
	wal_price = 45.48;
	intel_price = 20.77;
	wal_vol = 0.05;
	intel_vol = 0.05;
	rou = 0.1;
	rate = 0.05;
	coupon = 0.04075;
	long n = 1;
	Warrant war(wal_price, intel_price, rate, coupon, 2, wal_vol, intel_vol, rou,false,n);
	TrinomialLattice p(&war, 168, 252, gridFunc, payOffFunc);
	p.terPayoff_FSG();
	p.backwardEval_FSG();
	cout << "warrant value is " << p.war_value[p.steps][p.steps][0];
	cin >> rate;
}