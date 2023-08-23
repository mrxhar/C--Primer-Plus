// p4_lotto.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
long double probability(unsigned int, unsigned int);

int main()
{
	using namespace std;

	double total, choices;
	long double field= probability(47, 5);
	long double special = probability(27, 1);
	long double result = field * special;
	cout << "You have one chance in " << result;
	cout << " of winning.\n";
	/*
	cout << "Enter the total number of choice on the game card and\n"
		<< "the number of picks allowed:\n";
	
	while ((cin >> total >> choices) && choices <= total)
	{
		cout << "You have one chance in " << probability(total, choices);
		cout << " of winning.\n";
		cout << "Next tow number (q to quit): ";
	}
	*/
	cout << "bye.\n";
	return 0;
}

long double probability(unsigned int  numbers, unsigned int picks) {
	long double result = 1.0;
	long double n;
	unsigned p;
	for (n= numbers,p=picks; p >0;  n-- ,p--)
	{
		result = result * n / p;
	}
	return result;
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
