#include "text4.h"
using namespace SALES;

int main(void)
{
	double ar[QUARTERS] = { 11.1,22.2,33.3,44.4 };
	Sales s;
	setSales(s, ar, 3);
	showSales(s);

	setSales(s);
	showSales(s);
	return 0;
}