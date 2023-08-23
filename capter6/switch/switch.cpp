// switch.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
void showmenu();
void report();
void comfort();
int main()
{
	showmenu();
	int choise;
	cin >> choise;
	while (choise != 5)
	{
		switch (choise)
		{
		case 1: cout << "\a\n";
			break;
		case 2: report();
			break;
		case 3: cout << "The boss was in all day.\n";
			break;
		case 4:comfort();
			break;
		default: cout << "That's not a choise.\n";
		}
		showmenu();
		cin >> choise;
	}
	cout << "bye!\n";
	return 0;
}
void showmenu() {
	cout << "Please enter 1, 2, 3, 4, or 5:\n"
		"1) alarm             2) report\n"
		"3) alibi             4) comfort\n"
		"5) quit\n";
}
void report() {
	cout << "It's been \n";
}
void comfort() {
	cout << "Your employee \n";
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
