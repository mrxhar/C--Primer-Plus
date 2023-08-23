// pro6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
const int Years = 3;
const int Mounths = 12;

int main()
{
	using namespace std;
	const string mounth[Mounths] = { "1","2","3","4","5","6","7","8", "9", "10", "11", "12" };
	unsigned int counts[Years][Mounths];
	unsigned int s = 0;
	unsigned int total = 0;
	for (int year = 0; year < Years; ++year)
	{
		for (int mouth = 0; mouth < 12; mouth++)
		{
			cout << "第" << (year + 1) << "年，第" << mounth[mouth] << "月的销售量：" << endl;
			cin >> counts[year][mouth];
			s += counts[year][mouth];
		}
		cout << "当年销售总量为 ：" << s << endl;
		cout << "前 " << (year + 1) << "年的总销售量" << (total += s) << endl;
		s = 0;
	}

	return 0;
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
