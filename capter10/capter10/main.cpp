#include <iostream>
#include "p1.h"

int main(void)
{
	BankAccount n1("Rick", "0001", 1000);
	n1.show();

	std::cout << std::endl;
	n1.deposit(500.0);
	std::cout << "After deposit 500: \n";
	n1.show();

	std::cout << std::endl;
	n1.withdraw(800.0);
	std::cout << "After withdraw 800: \n";
	n1.show();
	return 0;
}