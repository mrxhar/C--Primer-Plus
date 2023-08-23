// pro7.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

struct car {
    string productName;
    int product_year;
};
int main()
{
    unsigned int car_num = 0;
    car* cars_p;
    cout << "How many cars do you wish to catalog?";
    cin >> car_num;
    cin.get(); // 空格还存在cin中，get消除
    cars_p = new car[car_num];
    for (int i = 0; i < car_num; i++)
    {
        cout << "Car #" << (i + 1) << ":\n";
        cout << "Please enter the make:";
        getline(cin,cars_p[i].productName);
        cout << "Please enter the year made:";
        cin >> cars_p[i].product_year;
        cin.get();
    }
    cout << "Here is your collection: \n";
    for (int i = 0; i < car_num; i++)
    {
        cout << cars_p[i].product_year << " " << cars_p[i].productName << endl;
    }
    delete [] cars_p;
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
