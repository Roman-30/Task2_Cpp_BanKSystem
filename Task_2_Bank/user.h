#pragma once
#include "userType.h"
#include <string>

using namespace std;

class User
{
public:
	User(string, string, int, double, Type);
	~User();
	string getName();
	void setName(string);

	string getLastName();
	void setLastName(string);

	int getPassport();
	void setPassport(int);

	double getCash();
	void setCash(double);

	int getType();
	void setType(Type);

	string toString();

private:
	string name;
	string lastName;
	int passport;
	double cash;
	Type type;
};
