﻿// p15_arrobj.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <array>
#include <string>

using namespace std;

const int Sensons = 4;
const array<string, Sensons> Snames = { "Spring","Summer","Fall","Winter" };

void fill(array<double, Sensons>* pa);
void show(array<double, Sensons> da);

int main()
{
    array<double, Sensons> expenses;
    fill(&expenses);
    show(expenses);
    return 0;
}

void fill(array<double, Sensons>* pa)
{
    for (int i = 0; i < Sensons; i++)
    {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> (*pa)[i]; // array 对象指针需要转换为 array 对象
    }
}
void show(array<double, Sensons> da)
{
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < Sensons; i++)
    {
        cout << Snames[i] << ": $" << da[i] << endl;
        total += da[i];
    }
    cout << "Total Expenses: $" << total << endl;
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
