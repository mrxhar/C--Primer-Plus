/*
@Author: mrxhar
@Date:   2023-08-28 07:59:58
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>

int main()
{
    using std::cin;
    using std::cout;
    char ch;
    cout << "enter a string ($ to quit)";
    int count = 0;

    while (cin.peek() != '$')
    {
        count += 1;
        cin.get(ch);
    }

    cout << "the string has " << count << " characters";

    while (cin.get(ch))
    {
        cout << ch;
    }
    return 0;
}
