// p7_arrfun3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int fill_array(double arr[], int limit);
void show_array(const double arr[], int n);
void revalue(double r, double arr[], int n);
const int Max = 5;

int main()
{
    double properties[Max];

    int size = fill_array(properties, Max);
    show_array(properties, size);

    if (size > 0)
    {
        cout << "Enter revalution factor: ";
        double factor;
        while (!(cin >> factor))
        {
            cin.clear();
            while (cin.get() != '\n')
            {
                continue;
            }
            cout << "Bad input: input process terminated: " << endl;
        }
        revalue(factor,properties,size);
        show_array(properties, size);
    }
    return 0;
}

int fill_array(double arr[], int limit) {
    double temp;
    int i;
    for (i = 0; i < limit; i++)
    {
        cout << "Enter value #" << i + 1 << ": ";
        cin >> temp;
        if (!cin) {
            cin.clear();
            while (cin.get() != '\n') // 清空缓冲区
            {
                continue;
            }
            cout << "Bad input: input process terminated: " << endl;
            break;
        }
        else if (temp < 0)
        {
            break;
        }
        else
        {
            arr[i] = temp;
        }
    }
    return i;
}


void show_array(const double arr[], int n) {
    for (int  i = 0; i < n; i++)
    {
        cout << "Property #" << i + 1 << ": $";
        cout << arr[i] << endl;
    }
}

void revalue(double r, double arr[], int n) {
    for (int  i = 0; i < n; i++)
    {
        arr[i] *= r;
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
