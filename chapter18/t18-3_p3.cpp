/*
@Author: mrxhar
@Date:   2023-08-28 17:16:40
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>

long double sum_value() { return 0; }

template <typename T>
long double sum_value(const T &t) { return t; }

template <typename T, typename... args>
long double sum_value(const T &t, const args &...arfg) { return t + sum_value(arfg...); }

int main()
{
    int n = 100;
    double m = 88.66;
    long y = 10000;
    char ch = 'x';
    std::cout << sum_value(n, m, y, ch, 'A', 77, 99.52);
    return 0;
}
