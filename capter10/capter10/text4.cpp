#include "text4.h"

using namespace std;

namespace SALES
{
	Sales::Sales(const double ar[], int n)
	{
		double total = 0;
		int i;
		for (i = 0; i < QUARTERS; i++)
		{
			sales[i] = ar[i];
			total += sales[i];
		}

		average = total / i;
		max = sales[0];
		min = sales[0];

		for (i =1; i < QUARTERS; i++)
		{
			max = max > sales[i] ? max : sales[i];
			min = min < sales[i] ? min : sales[i];
		}
		if (n < QUARTERS)
		{
			for (int k = n; k < QUARTERS; k++)
			{
				sales[k] = 0;
			}
		}
	}

	Sales::Sales()
	{
		double total = 0.0;
		int i;
		cout << "Enter " << QUARTERS << " sales quarters:\n";
		for (i = 0; i < QUARTERS; i++)
		{
			cout << "#" << i + 1 << ": ";
			cin >> sales[i];
			total += sales[i];

			if (i == 0)
			{
				max = sales[i];
				min = sales[i];
			}
			else
			{
				max = max > sales[i] ? max : sales[i];
				min = min < sales[i] ? min : sales[i];
			}
		}
		average = total / i;
	}

	void Sales::showSales() const
	{
		cout << "Sales of " << QUARTERS << " quarters:\n";
		for (int i = 0; i < QUARTERS; i++)
		{
			cout << sales[i] << " ";
		}
		cout << "\n";
		cout << "Average:" << average << endl;
		cout << "Max:" << max << endl;
		cout << "Min:" << min << endl;
	}
}