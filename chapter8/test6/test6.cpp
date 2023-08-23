// test5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

template <typename T>
T maxn(T t[],int n);
template <>
string maxn(string str[], int n);
int main()
{
	int arr_i[6] = { 1,3,5,6,1,3 };
	double arr_d[6] = { 123.123,412.123,412.123,312.31,3144.3 ,3123.31};

	string str[5] = { "Hello world","What's ","I love you","Good morning "," dsaf asd" };

	cout << maxn(arr_i,6) << endl;
	cout << maxn(arr_d,6) << endl;
	cout << maxn(str, 5);
	return 0;
}

template <typename T>
T maxn(T t[],int n ) {
	T max = t[0];
	for (int i = 1; i < n; i++)
	{
		max = max > t[i] ? max : t[i];
	}
	return max;
}

template <>
string maxn(string str[], int n) {
	int pos = 0;
	for (int i = 1; i < n; i++)
	{
		if (str[pos].size() < str[i].size())
		{
			pos  = i;
		}
	}
	return str[pos];
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
