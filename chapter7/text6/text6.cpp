// text6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

const int MAX = 40;

int Fill_array(double arr[], int n);
void Show_array(double arr[], int size);
void Reverse_array(double arr[], int size);

int main()
{
    double arr[MAX];

    int size = Fill_array(arr, MAX);
    Show_array(arr, size);
    Reverse_array(arr, size);
    Show_array(arr, size);
    Reverse_array(&arr[1], size - 2);
    Show_array(arr, size);

    return 0;
}
int Fill_array(double arr[], int n) {
    int i;
    double temp;
    for (i = 0; i < n; i++)
    {
        cout << "Enter a number:";
        cin >> temp;
        if (!cin)
        {
            cin.clear();
            while (cin.get() != '\n')
            {

            }
            break;
        }
        else
        {
            arr[i] = temp;
        }
    }
    return i;
}

void Show_array(double arr[], int size)
{
    cout << "The array content: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Reverse_array(double arr[], int size) {
    double temp;
    for (int i = 0; i < size / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
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
