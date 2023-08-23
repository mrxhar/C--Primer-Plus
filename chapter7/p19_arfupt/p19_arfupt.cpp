// p19_arfupt.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

const double* f1(const double* ar, int n);
const double* f2(const double ar[], int n);
const double* f3(const double ar[], int n);


int main()
{
    double av[3] = { 1112.3,1542.6,2227.9 };
    
    const double* (*p1) (const double*, int) = f1;
    auto p2 = f2;
    cout << "Part1-------------------";
    cout << "      Address      Value" << endl;
    cout << (*p1)(av, 3) <<": "<< * (*p1)(av, 3) << endl;;
    cout << p2(av, 3) << ": " << *p2(av, 3) << endl;

    const double* (*pa[3])(const double*, int) = { f1,f2,f3 };
    auto pb = pa;
    cout << "Part1-------------------";
    cout << "      Address      Value" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << (*pa[i])(av, 3) << ": " << *(*pa[i])(av, 3) << endl;
    }
    for (int i = 0; i < 3; i++)
    {
        cout << (*pb[i])(av, 3) << ": " << *(*pb[i])(av, 3) << endl;
    }

    // Part3
    auto pc = &pa;
    const double* (*(*pd)[3])(const double*, int) = &pa;
    cout << "Part3-------------------";
    cout << "      Address      Value" << endl;
    cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl;
    const double* pbd = (*pd)[1](av, 3);
    cout << pbd << ": " << *pbd << endl;
    //cout << (*pd)[2](av, 3) << ": " << *(*pd)[2](av, 3) << endl;
    cout << (*(*pd)[2])(av, 3) << ": " << *(*(*pd)[2])(av, 3) << endl;
    return 0;
}

const double* f1(const double* ar, int n) {
    return ar;
}

const double* f2(const double ar[], int n) {
    return ar + 1;
}

const double* f3(const double ar[], int n) {
    return ar + 2;
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
