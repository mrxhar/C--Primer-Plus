/*
@Author: mrxhar
@Date:   2023-08-26 16:13:00
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>

int main()
{
    using std::cin;
    using std::cout;

    cout << "Enter an integer: ";
    int n;
    cin >> n;

    cout << "n      n*n\n";
    cout << n << "      " << n * n << " (decimal)\n";
    cout << std::hex;
    cout << n << "      ";
    cout << n * n << " (hexadecimal)\n";

    cout << std::oct << n << "      " << n * n << " (octal)\n";

    dec(cout);
    cout << n << "      " << n * n << " (decimal)\n";

    return 0;
}