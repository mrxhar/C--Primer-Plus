/*
@Author: mrxhar
@Date:   2023-08-26 09:25:34
@Email:  1337904145@qq.com
@Blog:
*/

// 去除标点符号和空格，保留字母，字母全部变为小写
#include <iostream>
#include <string>
#include <cctype>

using namespace std;
bool isHui(const string &s);

int main()
{

    cout << "Test begin.\n";
    cout << "Please enter your input (empty input to quit): ";
    string input;
    getline(cin, input);
    while (cin && input.size() > 0)
    {
        if (isHui(input))
            cout << "What you input is a Hui string!\n";
        else
            cout << "What you input is not a Hui string!\n";
        cout << "Please enter your input (empty input to quit): ";
        getline(cin, input);
    }
    cout << "Test end. Quit.\n";
    system("pause");
    return 0;
}

bool isHui(const string &s)
{
    string str_test = s;
    // 使用迭代器

    for (auto i = str_test.begin(); i != str_test.end();)
    {
        if (!isalnum(*i))
        {
            i = str_test.erase(i);
            continue;
        }
        else
        {
            *i = tolower(*i);
            i++;
        }
    }
    string rev(str_test.rbegin(), str_test.rend());
    return rev == str_test;
}
