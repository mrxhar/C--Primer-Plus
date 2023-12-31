/*
@Author: mrxhar
@Date:   2023-08-28 16:45:45
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>
#include <initializer_list>

using namespace std;

template <typename T>
T average_list(initializer_list<T> ls)
{
    T sum = 0;
    int num = 0;
    for (auto p = ls.begin(); p < ls.end(); p++, num++)
    {
        sum += *p;
    }
    return sum / num;
}

int main()
{
    auto q = average_list({15.4, 10.7, 9.0});
    cout << q << endl;
    cout << average_list({20, 30, 19, 17, 45, 38}) << endl;
    auto ad = average_list<double>({'A', 70, 65.33});
    cout << ad << endl;
    return 0;
}
