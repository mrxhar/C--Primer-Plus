// p4_swaps.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

void swapr(int& a, int& b);
void swapp(int* pa, int* pb);
void swapv(int wallet1, int wallet2);

int main()
{
    int wallet1 = 300;
    int wallet2 = 350;

    cout << "wallet1 = " << wallet1 << endl;
    cout << "wallet2 = " << wallet2 << endl;
    
    cout << "Using reference to swap contents: " << endl;
    swapr(wallet1, wallet2);
    cout << "wallet1 = " << wallet1 << endl;
    cout << "wallet2 = " << wallet2 << endl;

    cout << "Using pointers to swap contents: " << endl;
    swapp(&wallet1, &wallet2);
    cout << "wallet1 = " << wallet1 << endl;
    cout << "wallet2 = " << wallet2 << endl;

    cout << "Using value to swap contents: " << endl;
    swapv(wallet1, wallet2);
    cout << "wallet1 = " << wallet1 << endl;
    cout << "wallet2 = " << wallet2 << endl;
    return 0;
}
void swapr(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void swapp(int* pa, int* pb)
{
    int temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}
void swapv(int wallet1, int wallet2) {
    int temp = wallet1;
    wallet1 = wallet2;
    wallet1 = temp;
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
