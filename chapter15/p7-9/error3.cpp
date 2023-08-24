/*
@Author: mrxhar
@Date:   2023-08-24 09:24:51
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
        try
        {
            z = hmean(x, y); // 可能激活异常的代码块
        }
        catch (const char *s) // catch 关键字捕获异常
        {                     // 异常采取的措施
            std::cout << s << std::endl;
            std::cout << "Enter a new pair of numbers: ";
            continue;
        }
        std::cout << "Harmonic mean of " << x << " and " << y
                  << " is " << z << std::endl;
        std::cout << "Enter next set of numbers <q to quit>: ";
    }
    std::cout << "Bye!\n";
    return 0;
}

double hmean(double x, double y)
{
    if (x == -y)
    {
        throw "bad heman() argument: x = -y not allowed"; // 表示引发了一个异常
    }
    return 2.0 * x * y / (x + y);
}