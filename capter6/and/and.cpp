// and.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

const int ArSize = 6;
int main()
{
    using namespace std;
    float naaq[ArSize];

    cout << "Enter the NAAQs (New Age Awareness Quotients) "
        << "of \nyour neighbors. Program terminates "
        << "when you make\n" << ArSize << "entries "
        << "or enter a negative value.\n";
    int i = 0;
    float temp;
    cout << "First value: ";
    cin >> temp;
    while (i < ArSize && temp >=0)
    {
        naaq[i] = temp;
        ++i;
        if (i < ArSize)
        {
            cout << "Next Value: ";
            cin >> temp;
        }
    }
    if (i == 0)
    { 
        cout << "No data--bye\n";
    }
    else
    {
        cout << "Enter your NAAQ: ";
        float you;
        int count = 0;
        cin >> you;
        for (int j = 0; j < i; j++)
        {
            if (naaq[j] > you)
            {
                ++count;
            }
            
        }
        cout << count;
        cout << " of your neighbors have greater awareness of\n"
                << "the New Age than you do.\n";
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
