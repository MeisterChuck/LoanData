#include "stdafx.h"
#include <stdio.h>
#include <fstream>

class LoanData {
	private:
		double Bal;
		double n;
		double i;
		double A;

	public:
		     LoanData(double p, double n, double e);
		void MakePayment(double a);
		void PrintAmortizationSchedule();
		void PrintPayOffTimeReport(double p, double e);
};

//Constructor
LoanData::LoanData(double p, double n, double e) {
	i = e / 1200;
	n = n * 12;
	A = p*((i*pow(1 + i, n)) - 1);
	Bal = p;
};


