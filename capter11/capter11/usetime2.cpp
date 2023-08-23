#include <iostream>
#include "mytime2.h"

int main()
{
	using std::cout;
	using std::endl;

	Time weeding(4, 35);
	Time waxing(2, 47);
	Time total;
	Time diff;
	Time adjusted;

	cout << "Weeding time = ";
	weeding.Show();

	cout << "waxing time = ";
	waxing.Show();

	cout << "total work time = ";
	total = weeding + waxing;
	total.Show();

	cout << "weeding time - waxing time = ";
	diff = weeding - waxing;
	diff.Show();

	adjusted = total * 1.5;
	cout << "adjusted work time = ";
	adjusted.Show();

}