#pragma once
#ifndef WARRANT_H
#define WARRANT_H

#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))

class Warrant {
public:
	double wal_price;
	double intel_price;
	double wal_exe_price;
	double intel_exe_price;
	double rate, coupon;
	double call_price;
	long notion;
	double vol_wal;
	double vol_intel;
	double corr;
	double maturity; 
	bool call_right;
	Warrant(double p1, double p2, double r, double c, double T,
		double vol1, double vol2, double rou, bool call,long n)
			:wal_price(p1),intel_price(p2),wal_exe_price(p1*0.87), intel_exe_price(p2*0.87),
			 maturity(T), rate(r), coupon(c), vol_wal(vol1), vol_intel(vol2), corr(rou),
			 call_right(call), notion(n),call_price(1){
	}
};
#endif