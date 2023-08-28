/*
@Author: mrxhar
@Date:   2023-08-26 19:37:48
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>
const int SLEN = 10;
inline void eatline()
{
    while (std::cin.get() != '\n')
        continue;
}

int main()
{

    using std::cin;
    using std::cout;
    using std::endl;

    // 定义字符串变量name，长度为SLEN
    char name[SLEN];
    // 定义字符串变量title，长度为SLEN
    char title[SLEN];

    // 输入字符串name
    cout << "Enter your name: ";
    cin.get(name, SLEN); 
    // 如果输入的字符串不是换行符，则提示用户输入的名字不足以容纳name
    if (cin.peek()!= '\n')
    {
        cout << "Sorry, we only have enough room for "
             << name << endl;
    }
    // 读取到换行符
    eatline();

    // 输入字符串title
    cout << "Dear " << name << ", enter your title: \n";
    cin.get(title, SLEN);
    // 如果输入的字符串不是换行符，则提示用户输入的标题不足以容纳title
    if (cin.peek()!= '\n')
    {
        cout << "We were forced to truncate your title.\n";
    }
    // 读取换行符
    eatline();
    // 输出字符串name和title
    cout << " Name: " << name
         << "\nTitle: " << title << endl;

    return 0;
}