#include "vector.h"
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>

int main()
{
	using namespace std;
	using VECTOR::Vector;


	ofstream outFile;
	string path;

	cout << "Enter .txt file path!\n";
	getline(cin, path);
	outFile.open(path);

	srand(time(0)); // ����һ�������������

	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0.0;
	double target;
	double dstep;

	cout << "Enter target distance (q to quit): ";

	while (cin >> target)
		// �������������Ĳ���ת��Ϊdouble ���ͣ�����
		// ����ֹͣ
	{
		outFile << "Target Distance: " << target;
		cout << "Enter step length: ";

		if (!(cin >> dstep))
		{
			break;
		}
		outFile << ", Step Size: " << dstep << endl;
		while (result.magval() < target) // ����û��
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL); // �µ����
			result = result + step;
			result.rect_mode();
			outFile << steps << ": " << result << endl;
			steps++;

		}

		
		cout << "After " << steps << " steps, the "
			<< "subject has the following location:\n";
		outFile << "After " << steps << " steps, the "
			<< "subject has the following location:\n";

		cout << result << endl;
		outFile << result << endl;

		result.polar_mode();

		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = "
			<< result.magval() / steps << endl;

		outFile << " or\n" << result << endl;
		outFile << "Average outward distance per step = "
			<< result.magval() / steps << endl;

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