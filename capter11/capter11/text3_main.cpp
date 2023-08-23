#include <iostream>
#include "text3.h"
#include <ctime>
#include <cstdlib>

int main()
{
	using namespace std;
	using VECTOR::Vector;

	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0.0;
	double target;
	double dstep;
	int num;

	cout << "Enter target distance (q to quit): ";

	while (cin >> target)
		// �������������Ĳ���ת��Ϊdouble ���ͣ�����
		// ����ֹͣ
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
		{
			break;
		}
		cout << "Enter N: ";
		cin >> num;
		
		double total = 0;
		double max;
		double min;
		for (int i = 0; i < num; i++)
		{
			srand(i); // ÿ��ѭ������Ҫһ���µ��������������
			while (result.magval() < target) // ����û��
			{
				direction = rand() % 360;
				step.reset(dstep, direction, Vector::POL); // �µ����
				result = result + step;
				steps++;
			}
			cout << "\n#" << i + 1 << "\n";
			cout << "After " << steps << " steps, the "
				<< "subject has the following location:\n";

			cout << result << endl;

			result.polar_mode();
			cout << " or\n" << result << endl;
			cout << "Average outward distance per step = "
				<< result.magval() / steps << endl;

			if (i == 0)
			{
				min = max = steps;
			}
			min = min < steps ? min : steps;
			max = max > steps ? max : steps;
			total += steps;

			steps = 0;
			result.reset(0.0, 0.0);
		}

		cout << num << " cycle max steps : " << max
			<< ", min steps = " << min << ", average step = " << total / num
			<< endl;

		// ��һѭ��
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