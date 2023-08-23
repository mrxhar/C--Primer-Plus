// text4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
using namespace std;

struct stringy
{
    char* str;
    int ct;
};

void set(stringy& str, const char* source);
void show(const stringy& str, int n = 1);
void show(const char* str, int n = 1);

int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";

    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);

    return 0;
}

void set(stringy & str, const char* source) {
    str.ct = (int)strlen(source) + 1;
    str.str =  new char[str.ct];
    strcpy(str.str,source);
}

void show(const stringy& str, int n) {
    for (int i = 0; i < n; i++)
    {
        cout << str.str << endl;
    }
}

void show(const char* str, int n) {
    for (int i = 0; i< n; i++)
    {
        cout << str << endl;
    }
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
