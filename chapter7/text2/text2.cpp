// text2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

const int MAX = 10;

int fill_golf(double[], int);
void show_golf(double[], int);
double average_golf(double[], int);
int main()
{
	double golf[MAX];

	int size = fill_golf(golf, MAX);

	if (size > 0)
	{
		show_golf(golf, size);
		double average = average_golf(golf, size);
		cout << "golf average: " << average << endl;
	}
	else
	{
		cout << "There is no scores!\n";
	}
	return 0;
}

int fill_golf(double ar[], int n) {

	double temp;
	int i;
	for (i = 0; i < MAX; i++)
	{
		cout << "Enter golf score: No." << i + 1 << ": ";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Invalid input, terminate.\n";
			break;
		}
		else if (temp < 0)
		{
			break;
		}
		else {
			ar[i] = temp;
		}
 	}
	return i;
}

void show_golf(double ar[], int n) {
	cout << "golf result : ";
	for (int i = 0; i < n; i++)
	{
		cout << ar[i] << " ";
	}
	cout << endl;
}

double average_golf(double ar[], int n) {
	double average;
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += ar[i];
	}
	return sum / n;
}






// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
