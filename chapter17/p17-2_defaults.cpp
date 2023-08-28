/*
@Author: mrxhar
@Date:   2023-08-26 16:06:31
@Email:  1337904145@qq.com
@Blog:
*/
#include <iostream>

int main()
{
    using std::cout;

    cout << "123456789012345678901234567890\0";
    char ch = 'K';
    int t = 273;
    cout << ch << ":\n";
    cout << t << ":\n";
    cout << -t << ":\n";

    double f1 = 1.200;
    cout << f1 << ":\n";
    cout << (f1 + 1.0 / 9.0) << ":\n";

    double f2 = 1.67E2;
    cout << f2 << ":\n";
    f2 += 1.0 / 9.0;
    cout << f2 << ":\n";
    cout << (f2 * 1.0e4) << ":\n"; // 超过六位 输出 科学记数法

    double f3 = 2.3e-4;
    cout << f3 << ":\n";
    cout << f3 / 10 << ":\n";

    return 0;
}
