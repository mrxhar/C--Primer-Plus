/*
@Author: mrxhar
@Date:   2023-08-24 09:33:44
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>

class bad_hmean
{
private:
    double v1;
    double v2;

public:
    bad_hmean(double a = 0.0, double b = 0.0) : v1(a), v2(b){};
    void mesg();
};

void bad_hmean::mesg()
{
    std::cout << "hmean(" << v1 << ", " << v2 << "): "
              << "invalid arguments: a = -b\n";
}

class bad_gmean
{
public:
    double v1;
    double v2;
    bad_gmean(double a = 0.0, double b = 0.0) : v1(a), v2(b){};
    const char *mesg();
};

inline const char *bad_gmean::mesg()
{
    return "gmean() argument should be >= 0\n";
}