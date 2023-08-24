/*
@Author: mrxhar
@Date:   2023-08-24 14:46:32
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>
#include <cmath>
#include <string>
#include "exc_mean.h"

class demo
{
private:
    std::string word;

public:
    demo(const std::string &str)
    {
        word = str;
        std::cout << "demo " << word << " created\n";
    }
    ~demo()
    {
        std::cout << "demo " << word << " destroyed\n";
    }
    void show() const
    {
        std::cout << "demo " << word << " lives!\n";
    }
};

double hmean(double x, double y);
double gmean(double x, double y);
double means(double x, double y);

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    double x, y, z;

    {
        demo d1("found in block in main()");
        cout << "Enter two numbers: ";
        while (cin >> x >> y)
        {

            try
            {
                z = means(x, y); // 新函数
                cout << "Harmonic mean of " << x << " and " << y
                     << " is " << z << endl;
                cout << "Enter next pair: ";
            }
            catch (bad_hmean &bg)
            {
                bg.mesg(); // means(x, y) 一遍，这是第二遍
                cout << "Try again.\n";
                continue;
            }
            catch (bad_gmean &hg)
            {
                cout << hg.mesg();
                cout << "Values used: " << hg.v1 << ", "
                     << hg.v2 << endl;
                cout << "Sorry, you don't get to play any more.\n";
                break; // 结束循环后 会到体的结尾
            }
        }
        d1.show(); 
    } // 结束后 destoryed

    cout << "Bye!" << endl;
    return 0;
}

double hmean(double x, double y)
{
    if (x == -y)
    {
        throw bad_hmean(x, y);
    }
    return 2.0 * x * y / (x + y);
}

double gmean(double x, double y)
{
    if (x < 0 || y < 0)
    {
        throw bad_gmean(x, y);
    }
    return std::sqrt(x * y);
}

double means(double x, double y)
{
    double am, hm, gm;
    demo d2("found in means()");
    am = (x + y) / 2.0;
    try
    {
        hm = hmean(x, y); // 都有对应的异常弹出
        gm = gmean(x, y); // 有异常，没有对应的catch 会默认弹出
    }
    catch (bad_hmean &bg)
    {
        bg.mesg();
        std::cout << "Caught bad means()\n";
        throw;
    }
    d2.show(); // alived 异常不会进行到这，直接跳出函数体，释放类空间
    return (am, hm, gm) / 3.0;
} // 函数调用时候的