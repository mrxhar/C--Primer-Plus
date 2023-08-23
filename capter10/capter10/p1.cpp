#include "p1.h"
#include <iostream>

using std::cout;
using std::endl;

BankAccount::BankAccount(string client, string num, double bal)
{
	name = client;
	accountnum = num;
	balance = bal;
}

void BankAccount::show(void) const
{
	cout << "The Account information: " << endl;
	cout << "Name: " << name << endl;
	cout << "Account: " << accountnum << endl;
	cout << "Balance: " << balance << endl;
}

void BankAccount::deposit(double crash) {
	balance += crash;
}

void BankAccount::withdraw(double crash)
{
	balance -= crash;
}
