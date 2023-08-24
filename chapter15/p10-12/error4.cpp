/*
@Author: mrxhar
@Date:   2023-08-24 14:46:32
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>
#include <cmath>
#include "exc_mean.h"

double hmean(double x, double y);
double gmean(double x, double y);

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    double x, y, z;

    cout << "Enter two numbers: ";
    while (cin >> x >> y)
    {
        try
        {
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y
                 << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y
                 << " is " << gmean(x, y) <<" ......."<< endl;
            cout << "Enter next set of numbers <q to quit> ";
        }
        catch (bad_hmean &bg)
        {
            bg.mesg();
            cout << "Try again.\n";
            continue;
        }
        catch (bad_gmean &hg)
        {
            cout << hg.mesg() << endl;
            cout << "Values used: " << hg.v1 << ", " << hg.v2 << endl;
            cout << "Sorry, you don't get to play any more.\n";
            break;
        }
    }
    cout << "Bye!" << endl;
    return 0;
}

double hmean(double x, double y)
{
    if ( x == -y)
    {
        throw bad_hmean(x,y);
    }
    return 2.0 * x * y /(x + y);
}

double gmean(double x, double y)
{
    if(x < 0 || y < 0)
    {
        throw bad_gmean(x, y);
    }
    return std::sqrt(x * y);
}