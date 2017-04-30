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
	wal_vol = 0.10;
	intel_vol = 0.20;
	rou = 0.0001;
	rate = 0.05;
	coupon = 0.04075;
	int numberOfSteps = 168;
	int numberOfYear = 252;
	long n = 1;
	/*
    The variation of warrant's price w.r.t various parameters;
	*/

  //  	ofstream myfile;
	// // correlation coefficient between the stock price processes:
	// myfile.open("rou_para.txt");
	// myfile << "rou,withcall,withoutcall" << endl;
	// for (double i_rou = -0.9; i_rou <= 0.9; i_rou += 0.2) {
	// 	cout << "processing: rou " << i_rou << endl;
	// 	Warrant war(wal_price, intel_price, rate, coupon, 2, wal_vol, intel_vol, i_rou,true,n);
	// 	TrinomialLattice p(&war, numberOfSteps, numberOfYear, gridFunc, payOffFunc);
	// //	cout << p.triprob[0] << ' ' << p.triprob[1] << ' ' << p.triprob[2] << ' ' << p.triprob[3] << endl;
	// 	p.terPayoff_FSG();
	// 	p.backwardEval_FSG();
	// 	double val_with_call = p.war_value[p.steps][p.steps][0];
	// 	p.delMem(p.war_value);
	// 	p.terPayoff_noFSG();
	// 	p.backwardEval_noFSG();
	// 	double val_without_call = p.war_value[p.steps][p.steps][0];
	// 	p.delMem(p.war_value);
	// 	myfile << i_rou << "," << val_with_call << "," << val_without_call << endl;
	// }
	// myfile.close();
	// system("pause");
	// //volatility of stock prices
	// myfile.open("vol_para.txt");
	// myfile << "vol,withcall,withoutcall" << endl;
	// for (double i_wal_vol = 0.01; i_wal_vol <= 0.40; i_wal_vol += 0.02) {
	// 	cout << "processing: vol " << i_wal_vol << endl;
	// 	Warrant war(wal_price, intel_price, rate, coupon, 2, i_wal_vol, intel_vol, rou,true,n);
  //   	TrinomialLattice p(&war, numberOfSteps, numberOfYear, gridFunc, payOffFunc);
	//     p.terPayoff_FSG();
	//     p.backwardEval_FSG();
	// 	double val_with_call = p.war_value[p.steps][p.steps][0];
	// 	p.delMem(p.war_value);
	// 	p.terPayoff_noFSG();
	// 	p.backwardEval_noFSG();
	// 	double val_without_call = p.war_value[p.steps][p.steps][0];
	// 	myfile << i_wal_vol << "," << val_with_call << "," << val_without_call << endl;
	// 	p.delMem(p.war_value);
	// }
	// myfile.close();
	// //level of riskless rate
	// myfile.open("rate_para.txt");
	// myfile << "rate,withcall,withoutcall" << endl;
	// for (double i_rate = 0.0; i_rate <= 0.1; i_rate += 0.01) {
	// 	cout << "processing: rate " << i_rate << endl;
	// 	Warrant war(wal_price, intel_price, i_rate, coupon, 2, wal_vol, intel_vol, rou,true,n);
  //   	TrinomialLattice p(&war, numberOfSteps, numberOfYear, gridFunc, payOffFunc);
	//     p.terPayoff_FSG();
	//     p.backwardEval_FSG();
	// 	double val_with_call = p.war_value[p.steps][p.steps][0];
	// 	p.delMem(p.war_value);
	// 	p.terPayoff_noFSG();
	// 	p.backwardEval_noFSG();
	// 	double val_without_call = p.war_value[p.steps][p.steps][0];
	// 	myfile << i_rate << "," << val_with_call << "," << val_without_call << endl;
	// 	p.delMem(p.war_value);
	// }
	// myfile.close();

	/*
    the price for call right
	*/
	// at the same time, validate the method using PV instead of FSSG;

	Warrant war(wal_price, intel_price, rate, coupon, 2, wal_vol, intel_vol, 0.90, true, n);
	TrinomialLattice p(&war, numberOfSteps, numberOfYear, gridFunc, payOffFunc);
	p.terPayoff_FSG();
	p.backwardEval_FSG();
	cout << p.war_value[p.steps][p.steps][0] << endl;
	p.delMem(p.war_value);
	p.terPayoff_noFSG();
	p.backwardEval_noFSG();
	cout << p.war_value[p.steps][p.steps][0] << endl;
	system("pause");


}
