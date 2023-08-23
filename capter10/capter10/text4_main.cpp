#include "text4.h"

int main(void)
{
	using namespace SALES;
	double ar[4] = { 11.1,22.2,33.3,44.4 };

	Sales s1(ar, QUARTERS);
	Sales s2;

	std::cout << "\nNow show two info:\n";
	s1.showSales();
	s2.showSales();
}