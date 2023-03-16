
#include <string>
#include <map>
#include "account.h"
#include "bank.h"
#include "user.h"
#include <iostream>

using namespace std;


Bank::Bank(int id, string name)
{
	this->id = id;
	this->name = name;
	this->bankCash = 1000;
	this->accounts = {};
	this->percent = (double) 13 / 100;
} 

Bank::Bank(int id, string name, double bankCash, double percent)
{
	this->id = id;
	this->name = name;
	this->bankCash = bankCash;
	this->accounts = {};
	this->percent = percent / 100;
}

int Bank::getId()
{
	return this->id;
}

void Bank::setId(int id)
{
	this->id = id;
}

string Bank::getName()
{
	return this->name;
}
void Bank::setName(string name)
{
	this->name = name;
}

double Bank::getBankCash()
{
	return this->bankCash;
}
void Bank::setBankCash(double bankCash)
{
	this->bankCash = bankCash;
}

double Bank::getPercent() 
{
	return this->percent;
}
void Bank::setPercent(double persent)
{
	this->percent = persent;
}

vector<Account>& Bank::getAccounts()
{
	return this->accounts;
}

void Bank::addAccount(User user)
{

	accounts.push_back(Account{ user.getPassport() });
	
}

void Bank::upDateCash(double cash, bool flag)
{
	double oldCash = getBankCash();
	if (flag) {

		setBankCash(oldCash + cash);
	} 
	else
	{
		setBankCash(oldCash - cash);
	}
}

string Bank::toString()
{
	string line;

	for (auto& i : this->accounts) {
	
		line += i.toString() + "\n";
	}

	return "Имя " + this->name + ", ID " + to_string(this->id) + ", Денег в банке " + to_string(this->bankCash) + ", процент " + to_string(this->percent) + ", счета:\n" + line;
}