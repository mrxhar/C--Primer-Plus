/*
@Author: mrxhar
@Date:   2023-08-24 09:17:13
@Email:  1337904145@qq.com
@Blog:   
*/

#include <iostream>
#include <cfloat>

bool hmean(double a, double b,double* ans);

int main()
{
    double x, y, z;

    std::cout << "Enter two numbers: ";
    while (std::cin >> x >> y)
    {
        if( hmean(x, y, &z))
        {
            std::cout << "Harmonic mean of " << x << " and " << y
                      << " is " << z << std::endl;
        }
        else
        {
            std::cout << "One value should not be the negative "
                      << "of the other - try again.\n";
        }
        std::cout << "Enter next set of numbers <q to quit>: ";
    }
    std::cout << "Bye!\n";
    return 0;
}

bool hmean(double x, double y,double* ans)
{
    if (x == -y)
    {
        *ans = DBL_MAX;
        return false;
    }
    else{

        *ans = 2.0 * x * y / (x + y);
        return true;
    }
}