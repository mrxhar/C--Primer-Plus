#ifndef __P4__H__
#define __P4__H__

#include <iostream>

namespace SALES
{
	const int QUARTERS = 4;

	class Sales
	{
	public:
		Sales();
		Sales(const double ar[], int n);
		void showSales() const;

	private:
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	};
}
#endif // !__P4__H__
