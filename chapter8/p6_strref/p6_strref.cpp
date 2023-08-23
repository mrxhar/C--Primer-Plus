// p6_strref.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

struct free_throws
{
	string name;
	int made;
	int attempts;
	float precent;
};

void set_pc(free_throws& ft);
void display(const free_throws& ft);
free_throws& accumulate(free_throws& target, const free_throws& source);
int main()
{
	free_throws one = { "Rick",13,14 };
	free_throws two = { "Jack",10,16 };
	free_throws three = { "Jerry",7,9 };
	free_throws four = { "Jason",5,9 };
	free_throws five = { "Micheal",6,14 };
	free_throws team = { "Rose",0,0 };
	
	free_throws dup;

	set_pc(one);
	display(one);
	accumulate(team, one);
	display(team);
	display(accumulate(team, two));
	accumulate(accumulate(team, three), four);
	display(team);
	dup = accumulate(team, five);
	display(dup);
}

void set_pc(free_throws& ft) {
	if (ft.attempts != 0)
	{
		ft.precent = (float)ft.made / (float)ft.attempts;
	}
	else
	{
		ft.precent = 0;
	}
}

void display(const free_throws& ft)
{
	cout << "Name: " << ft.name << "\n";
	cout << "  Made: " << ft.made << "\t";
	cout << "Attempts: " << ft.attempts << "\t";
	cout << "Precent: " << ft.precent << "\n";
}

free_throws& accumulate(free_throws& target, const free_throws& source)
{
	target.attempts += source.attempts;
	target.made += source.made;
	set_pc(target);
	return target;
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
