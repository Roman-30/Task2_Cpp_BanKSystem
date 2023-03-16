#pragma once
#include <string>
#include <map>
#include <vector>
#include "account.h"
#include "user.h"

using namespace std;


class Bank
{
public:
	Bank(int id, string name);

	Bank(int id, string name, double bankCash, double percent);

	int getId();
	void setId(int);

	string getName();
	void setName(string name);

	double getBankCash();
	void setBankCash(double);

	double getPercent();
	void setPercent(double);

	vector<Account>& getAccounts();

	string toString();

	void addAccount(User);

	void upDateCash(double, bool);


private:
	int id;
	string name;
	double bankCash;
	vector<Account> accounts{};
	double percent;
};

