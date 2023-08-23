#include <iostream>
#include "namesp.h"

int main(void) {
	using debts::Debt;
	using debts::showDebt;

	Debt golf = { {"Micheal","Jordan"},120.0 };
	showDebt(golf);
	return 0;
}