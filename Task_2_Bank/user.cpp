#include "user.h"
#include "userType.h"
#include <string>

using namespace std;

User::User(string name, string lastName, int passport, double cash, Type type)
{
	this->name = name;
	this->lastName = lastName;
	this->passport = passport;
	this->cash = cash;
	this->type = type;
};

User::~User()
{

}

string User::getName()
{
	return this->name;
}

void User::setName(string name)
{
	this->name = name;
}

string User::getLastName()
{
	return this->lastName;
}

void User::setLastName(string lastName)
{
	this->lastName = lastName;
}

int User::getPassport()
{
	return this->passport;
}

void User::setPassport(int passport)
{
	this->passport = passport;
}

double User::getCash() 
{
	return this->cash;
}

void User::setCash(double cash)
{
	this->cash = cash;
}

int User::getType()
{
	return this->type;
}

void User::setType(Type type)
{
	this->type = type;
}

string User::toString()
{
	string type;

	if (this->type == Type::Juridica) {
		type = "Juridica";
	} 
	else
	{
		type = "Physical";
	}

	return "Имя " + this->name + ", Фамилия " + this->lastName + ", Пасспорт " + to_string(this->passport) + ", деньги " + to_string(this->cash) + ", тип " + type + ".";
}