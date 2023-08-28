/*
@Author: mrxhar
@Date:   2023-08-28 14:41:17
@Email:  1337904145@qq.com
@Blog:
*/

#include "p18-6_somedefs.h"
#include <iostream>

double dub(double x) { return 2.0 * x; }
double square(double x) { return x * x; }

int main()
{
    using std::cout;
    using std::endl;

    double y = 1.21;
    cout << "Function pointer dub: \n";
    cout << "  " << use_f(y, dub) << endl;
    cout << "Function pointer square: \n";
    cout << "  " << use_f(y, square) << endl;
    cout << "Function object Fp:\n";
    cout << "  " << use_f(y, Fp(5.0));
    cout << "Function object Fq:\n";
    cout << "  " << use_f(y, Fq(5.0));
    cout << "Lambda expression 1:\n";
    cout << "  " << use_f(y, [](double u)
                          { return u * u; });

    cout << "Lambda expression 2:\n";
    cout << "  " << use_f(y, [](double u)
                          { return u + u / 2.0; });
    return 0;
}
