/*
@Author: mrxhar
@Date:   2023-08-26 16:58:48
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    using namespace std;

    cout << fixed << right;

    cout << setw(6) << "N" << setw(14) << "square root" << setw(15) << "fourth root\n";

    double root;
    for (int n = 10; n <= 100; n += 10)
    {
        root = sqrt(double(n));
        cout << setw(6) << setfill('.') << n << setfill(' ')
             << setw(12) << setprecision(3) << root
             << setw(14) << setprecision(4) << sqrt(root)
             << endl;
    }
    return 0;
}
