#ifndef _TEXT4_H_
#define _TEXT4_H_

# include <iostream>

namespace SALES
{
	const int QUARTERS = 4;
	struct Sales
	{
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	};

	void setSales(Sales& s, const double ar[], int n);
	void setSales(Sales& s);
	void showSales(const Sales& s);
}

#endif // !_TEXT4_H_

