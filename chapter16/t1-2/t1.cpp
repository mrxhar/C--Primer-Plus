/*
@Author: mrxhar
@Date:   2023-08-26 09:13:49
@Email:  1337904145@qq.com
@Blog:
*/
#include <iostream>
#include <string>

using namespace std;

bool ishuiwen(const string &s);

int main()
{
    cout << "Enter a string (quit to quit):\n";
    string input;
    while (cin >> input && input != "quit")
    {
        cout << input << (ishuiwen(input) == false ? "不是" : "是") << "回文字符串" << endl;
        cout << "Continue!";
    }

    return 0;
}

bool ishuiwen(const string &s)
{
    string rev(s.rbegin(), s.rend()); // 使用string的构造函数，利用两个迭代器构造
    return s == rev; // 使用 string 类 比较功能
}
