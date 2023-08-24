/*
@Author: mrxhar
@Date:   2023-08-24 09:08:28
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>
#include <cstdlib>

double hmean(double a, double b);

int main()
{
    double x, y, z;

    std::cout << "Enter two numbers: ";
    while (std::cin >> x >> y)
    {
        z = hmean(x, y);
        std::cout << "Harmonic mean of " << x << " and " << y
                  << " is " << z << std::endl;
    }
    std::cout << "Bye!\n";
    return 0;
}

double hmean(double x, double y)
{
    if (x == -y)
    {
        std::cout << "untenable argument to hmean()\n";
        std::abort(); // 编译器不同返回消息不同
    }
    return 2.0 * x * y / (x + y);
}