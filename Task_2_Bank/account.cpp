#include "account.h"
#include <string>
#include <iostream>

using namespace std;

Account::Account(int id) 
{
	this->id = id;
	this->summ = 0;
};

Account::Account(int id, double summ) {
	this->id = id;
	this->summ = summ;
}

string Account::toString()
{
	return "������� ������������: " + to_string(id) + ". ����� �� ����� --> " + to_string(summ);
}

int Account::getId() 
{
	return this->id;
}

double Account::getSum() 
{
	return this->summ;
}

void Account::setSum(double sum)
{
	this->summ = sum;
}

bool Account::updateSum(double sum, bool is_inserted)
{
	double oldSum = getSum();
	if (is_inserted) {
		setSum(oldSum + sum);
	}
	else
	{
		if (oldSum - sum < 0) {
			throw "�� ����� ������������ �������!";
		}
		else
		{
			setSum(oldSum - sum);
		}
	}
	return true;
}



