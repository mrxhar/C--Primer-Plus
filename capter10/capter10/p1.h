#ifndef __P1__H__
#define __P1__H__

#include <string>

using std::string;

class BankAccount
{
public:
	BankAccount(string client,string num,double bal	= 0.0);
	void show(void) const;
	void deposit(double crash);
	void withdraw(double crash);

private:
	string name;
	string accountnum;
	double balance;
};

#endif // !__P1__H__

