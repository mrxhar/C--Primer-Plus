/*
@Author: mrxhar
@Date:   2023-08-28 14:35:39
@Email:  1337904145@qq.com
@Blog:
*/

#ifndef __SOMEDEFS__H__
#define __SOMEDEFS__H__
#include <iostream>

template <typename T, typename F>
T use_f(T v, F f)
{
    static int count = 0;
    count++;
    std::cout << "  use_f count = " << count << ", &count = " << &count << std::endl;
    return f(v);
}

class Fp
{
private:
    double z_;

public:
    Fp(double z = 1.0) : z_(z){};
    double operator()(double p) { return p * z_; }
};

class Fq
{
private:
    double z_;

public:
    Fq(double z = 1.0) : z_(z) {}
    double operator()(double q) { return q + z_; }
};

#endif __SOMEDEFS__H__
