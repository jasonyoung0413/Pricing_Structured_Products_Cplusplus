#include "TrinomialLattice.h"
#include "PayOff.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	//start our programming;
	double wal_price, intel_price, wal_vol, intel_vol, rou;
	double rate,coupon;
	// initial value for all parameters:
	wal_price = 45.48;
	intel_price = 20.77;
	wal_vol = 0.02;
	intel_vol = 0.50;
	rou = 0.1;
	rate = 0.05;
	coupon = 0.04075;
	int numberOfSteps = 168;
	int numberOfYear = 252;
	long n = 1;
	/*
    The variation of warrant's price w.r.t various parameters;
	*/
   	ofstream myfile;
	// correlation coefficient between the stock price processes: 
	myfile.open("rou_para.txt");
	for (double i_rou = 0.0; i_rou <= 1; i_rou += 0.1) {
		cout << "processing: rou" << i_rou << endl;
		Warrant war(wal_price, intel_price, rate, coupon, 2, wal_vol, intel_vol, i_rou,true,n);
    	TrinomialLattice p(&war, numberOfSteps, numberOfYear, gridFunc, payOffFunc);
	    p.terPayoff_FSG();
	    p.backwardEval_FSG();
		myfile << i_rou << "," << p.war_value[p.steps][p.steps][0] << endl;
		p.delMem(p.war_value);
	}
	myfile.close();
	//volatility of stock prices
	myfile.open("vol_para.txt");
	for (double i_wal_vol = 0.05; i_wal_vol <= 0.50; i_wal_vol += 0.05) {
		cout << "processing: vol" << i_wal_vol << endl;
		Warrant war(wal_price, intel_price, rate, coupon, 2, i_wal_vol, intel_vol, rou,true,n);
    	TrinomialLattice p(&war, numberOfSteps, numberOfYear, gridFunc, payOffFunc);
	    p.terPayoff_FSG();
	    p.backwardEval_FSG();
		myfile << i_wal_vol << "," << p.war_value[p.steps][p.steps][0] << endl;
		p.delMem(p.war_value);
	}
	myfile.close();
	//level of riskless rate
	myfile.open("rate_para.txt");
	for (double i_rate = 0.01; i_rate <= 0.1; i_rate += 0.01) {
		cout << "processing: rate" << i_rate << endl;
		Warrant war(wal_price, intel_price, i_rate, coupon, 2, wal_vol, intel_vol, rou,true,n);
    	TrinomialLattice p(&war, numberOfSteps, numberOfYear, gridFunc, payOffFunc);
	    p.terPayoff_FSG();
	    p.backwardEval_FSG();
		myfile << i_rate << "," << p.war_value[p.steps][p.steps][0] << endl;
		p.delMem(p.war_value);
	}
	myfile.close();

	/*
    the price for call right	
	*/ 
	// at the same time, validate the method using PV instead of FSSG;
}