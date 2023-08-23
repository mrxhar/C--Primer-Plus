#include <iostream>
#include "text2.h"
#include <ctime>
#include <cstdlib>

int main()
{
	using namespace std;
	using VECTOR::Vector;

	srand(time(0)); // 设置一个随机数产生器

	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0.0;
	double target;
	double dstep;

	cout << "Enter target distance (q to quit): ";

	while (cin >> target)
		// 隐含了如果输入的不能转换为double 类型，将会
		// 主动停止
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
		{
			break;
		}

		while (result.magval() < target) // 距离没到
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL); // 新的随机
			result = result + step;
			steps++;
		}

		cout << "After " << steps << " steps, the "
			<< "subject has the following location:\n";

		cout << result << endl;

		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = "
			<< result.magval() / steps << endl;

		// 下一循环
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
	{
		continue;
	}
	return 0;
}