/*
@Author: mrxhar
@Date:   2023-08-26 16:24:46
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>

int main()
{
    using std::cout;
    cout.fill('*');
    const char *staff[2] = {"Wallo Whipsnade", "Wilmarie Wooper"};
    long bonus[2] = {900, 1350};

    for (int i = 0; i < 2; i++)
    {
        cout << staff[i] << ": $";
        cout.width(7);
        cout << bonus[i] << "\n";
    }

    return 0;
}
