

#include <iostream>
#include "text6.h"


int main()
{
	using std::cout;
	using std::cin;
	Stonewt sts[6]{
		120,200,131.31,
	};

	// 输入剩余的元素的值
	for (int i = 3; i < 6; i++)
	{
		double pound;
		cout << "Enter " << "#" << i + 1 << ": ";
		cin >> pound;
		sts[i] = pound;
	}
	for (int i = 0; i < 6; i++)
	{
		cout << "#" << i + 1 << ": ";
		sts[i].show_stn();
	}
	Stonewt st11(11, 0);
	int total = sts[0] > st11 ? 1 : 0;
	Stonewt max = sts[0];
	Stonewt min = sts[0];
	for (int i = 0; i < 6; i++)
	{
		max = max > sts[i] ? max : sts[i];
		min = min < sts[i] ? min : sts[i];
		total += sts[i] > st11 ? 1 : 0;
	}
	cout << "max = " ;
	max.show_stn();
	cout << "min = ";
	min.show_stn();

	cout << "num ( > 11 stone) = " << total << std::endl;

	return 0;
}