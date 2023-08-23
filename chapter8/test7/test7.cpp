// p14_temptempover.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

struct debtes {
    char name[50];
    double amount;
};

template <typename T>
void ShowArray(T arr[], int n);

template <typename T>
void ShowArray(T* arr[], int n);

template <typename T>
T SumArray(T arr[], int n);

template <typename T>
T SumArray(T* arr[], int n);

int main()
{
    using namespace std;
    int things[6] = { 13,31,103,301,310,130 };
    struct debtes mr_E[3] = {
        {"Ima Wilfe",2400.0},
        {"Ura Foxe",1300.0},
        {"Iby Stout",1800.0},
    };
    double* pd[3];
    for (int i = 0; i < 3; i++)
    {
        pd[i] = &mr_E[i].amount; // 指正数组指向结构数组的amount属性的地址
    }
    cout << "Listing Mr.E's count of things:\n";
    ShowArray(things, 6); // 这时候 things 是一个结构数组

    cout << "Listing Mr.E's Debtes:\n";
    ShowArray(pd, 3);

    cout << "The sum of things : " << SumArray(things, 6) << endl;
    cout << "The sum of pd: " << SumArray(pd, 3) << endl;
    return 0;
}

template <typename T>
void ShowArray(T arr[], int n) {
    using namespace std;
    cout << "template A\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
void ShowArray(T* arr[], int n) {
    using namespace std;
    cout << "template B\n";
    for (int i = 0; i < n; i++)
    {
        cout << *arr[i] << " "; // 指针对应的值
    }
    cout << endl;
}

template <typename T>
T SumArray(T arr[], int n) {
    T sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}


template <typename T>
T SumArray(T* arr[], int n) {
    T sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += *arr[i];
    }
    return sum;
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
