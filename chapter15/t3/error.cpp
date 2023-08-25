/*
@Author: mrxhar
@Date:   2023-08-25 09:31:00
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>
#include <string>
#include <stdexcept>

#include <cmath>

class bad : public std::logic_error
{
public:
    std::string name;
    double v1;
    double v2;

    explicit bad(const std::string &n, const std::string &s, double a = 0.0, double b = 0.0) : logic_error(s), name(n), v1(a), v2(b){};
    void mesg();
    virtual ~bad(){};
};
inline void bad::mesg()
{
    std::cout << "Error happened!\n";
}

class bad_hmean : public bad
{

public:
    bad_hmean(const std::string &n = "hmean()", const std::string &s = "Error in hmean()", double a = 0.0, double b = 0.0) : bad(n, s, a, b){};
    void mesg();
    const char *what() { return "bad arguments in hmeam()"; };
    virtual ~bad_hmean() throw(){};
};

inline void bad_hmean::mesg()
{
    std::cout << "hmean(" << v1 << ", " << v2 << "): "
              << "invalid arguments: a = -b\n";
}

class bad_gmean : public bad
{
public:
    bad_gmean(const std::string &n = "gmean()", const std::string &s = "Error in gmean()", double a = 0.0, double b = 0.0) : bad(n, s, a, b){};
    virtual ~bad_gmean() throw(){};
    const char *what() { return "bad arguments in gmeam()"; };
    const char *mesg();
};

inline const char *bad_gmean::mesg()
{
    return "gmean() arguments should be >= 0\n";
}

double hmean(double x, double y)
{
    if (x == -y)
    {
        throw bad("hmean", "Error in hmean()\n", x, y);
    }
    return 2.0 * x * y / (x + y);
}

double gmean(double x, double y)
{
    if (x < 0 || y < 0)
    {
        throw bad("gmean", "Error in gmean()\n", x, y);
    }
    return std::sqrt(x * y);
}

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
            cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x, y) << endl;
            cout << "Enter next set of two numbers <q to quit>: ";
        }
        catch (bad &b) // 一个 catch 块
        {
            b.mesg();
            if (b.name == "hmean")
            {
                cout << ((bad_hmean &)b).what();
                cout << "Error message: ";
                ((bad_hmean &)b).mesg();
                cout << "Sorry, you don't get to play any more.\n";
                break;
            }
            else if (b.name == "gmean")
            {
                cout << ((bad_gmean &)b).what();
                cout << "Error message: ";
                cout << ((bad_gmean &)b).mesg();
                cout << "Values used: " << ((bad_gmean &)b).v1 << ", " << ((bad_gmean &)b).v2 << endl;
                cout << "Sorry, you don't get to play any more.\n";
                break;
            }
            else
            {
                cout << "Input error.\nTerminated.\n";
                system("pause");
                exit(EXIT_FAILURE);
            }
        }
    }

    cout << "Bye!\n";
    system("pause");
    return 0;
}
