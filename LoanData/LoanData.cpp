#include "stdafx.h"
#include <stdio.h>
#include <fstream>

class LoanData {
	private:
		double Bal,
			n,
			i,
			A;

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

//Function is used to make payments and recalculates the balance
void LoanData::MakePayment(double a) {
	Bal = (i + 1)*Bal - a;
};

//Function prints out amounts to separate txt file
void LoanData::PrintAmortizationSchedule() {
	double payment,
		interestPaid,
		principlePaid,
		endingBalance;
	double beginningBalance = Bal;

	int length = 1, amount = (int)Bal;

	if (amount > 0) {
		for (length = 0; amount > 0; length++) {
			amount /= 10;
		}
	}

	length += 3;

	//FILE *pFile = NULL;
	//Open the file
	//pFile = fopen("results.dat", "w");

	printf("Beginning Bal.   Interest paid   Principle paid   Ending Balance.\n");
	//fprintf(pFile, "Beginning Bal.   Interest paid   Principle paid   Ending Balance.\n");

	while (beginningBalance > 0) {
		if (i + 1 * Bal > A) {
			payment = A;
		}
		else {
			payment = (i + 1)*Bal;
		}

		interestPaid = i*beginningBalance;
		principlePaid = A - interestPaid;
		endingBalance = (i + 1)*beginningBalance - A;
		
		printf("$%*.2f    $%*.2f    $%*.2f    $%*.2f\n",
			beginningBalance,
			interestPaid,
			principlePaid,
			endingBalance);
		/*fprintf(pFile, "$%-*.2f    $%-*.2f    $%-*.2f    $%-*.2f\n",
			length,
			beginningBalance,
			length,
			interestPaid,
			length,
			principlePaid,
			length,
			endingBalance);
			*/

		beginningBalance = endingBalance;

		//fclose(pFile);
	}
};

//Optional function
void LoanData::PrintPayOffTimeReport(double p, double e) {
	//FILE *cFile = NULL;
	//cFile = fopen("data.dat", "w");

	printf("n      A\n");
	//fprintf(cFile, "n      A\n");

	A = p*((i*pow(1 + i, 1)) / (pow(1 + i, 1) - 1));
	int length = 1,
		amount = (int)A;

	if (amount > 0) {
		for (length = 0; amount > 0; length++) {
			amount /= 10;
		}
	}

	length += 3;

	for (int n = 1; n <= 50; n++) {
		A = p*((i*pow(1 + i, n)) / (pow(1 + i, n) - 1));

		printf("%*i    $%*2lf\n",
			n,
			A);
		/*fprintf(cFile, "%-*i    $%-*2lf\n",
			length,
			n,
			length,
			A);*/
	}

	//fclose(cFile);
};

//Main function
int main(int argc, char*argv[]) {
	double p,
		n,
		e;

	printf("\nLoan amount is: ");
	scanf("\n%lf", &p);
	printf("\nNumber of years to pay off loan is: ");
	scanf("\n%lf", &n);
	printf("\nYearly interest rate is: ");
	scanf("\n%lf", &e);
	printf("\nResults printed to results.dat");
	printf("\nResults printed to data.dat\n\n");

	LoanData data(p, n, e);
	data.MakePayment(650.00);
	data.PrintAmortizationSchedule();
	data.PrintPayOffTimeReport(p, e);

	return 0;
}


