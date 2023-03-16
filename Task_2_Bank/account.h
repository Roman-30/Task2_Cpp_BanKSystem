#pragma once
#include <string>

using namespace std;

class Account
{
public:
	Account(int, double);
	Account(int);
	string toString();
	int getId();
	double getSum();
	void setSum(double);
	bool updateSum(double, bool);

private:
	int id;
	double summ;
};

