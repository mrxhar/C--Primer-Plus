/*
@Author: mrxhar
@Date:   2023-08-23 08:13:07
@Email:  1337904145@qq.com
@Blog:
*/

#ifndef __WINEC__H__
#define __WINEC__H__

#include <iostream>
#include <string>
#include <valarray>

using std::cin;
using std::cout;

template <class T1, class T2>
class Pair
{
private:
    T1 a;
    T2 b;

public:
    void set(const T1 &yr, const T2 &bot);
    Pair(const T1 &aval, const T2 &bval) : a(aval), b(bval){};
    Pair(){};
    int Sum() const;
    void Show(int y) const;
};

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine : private std::string, private PairArray
{
private:
    int yrs;

public:
    Wine(const char *l, int y, const int yr[], const int bot[]) : std::string(l), yrs(y), PairArray(ArrayInt(yr, y), ArrayInt(bot, y)){};
    Wine(const char *l, int y) : std::string(l), yrs(y){};
    void GetBottes();
    std::string &Label();
    int Sum() const;
    void Show() const;

    // congzai
};

// Pair

template <class T1, class T2>
void Pair<T1, T2>::set(const T1 &yr, const T2 &bot)
{
    a = yr;
    b = bot;
}

template <class T1, class T2>
int Pair<T1, T2>::Sum() const
{
    return b.sum();
}

template <class T1, class T2>
void Pair<T1, T2>::Show(int y) const
{
    for (int i = 0; i < y; i++)
    {
        cout << "\t\t" << a[i] << "\t\t" << b[i] << "\n";
    }
}

// Wine

// Wine::Wine(const char *l, int y, const int yr[], const int bot[])
// {
//     name = l;
//     yrs = y;
//     b.set(ArrayInt(yr, yrs), ArrayInt(bot, yrs)); // 要知道ArrayInt 的构造方法
// }

// Wine::Wine(const char *l, int y)
// {
//     yrs = y;
//     name = l;
// }

void Wine::GetBottes()
{
    ArrayInt yr(yrs), bot(yrs);
    cout << "Enter " << (const std::string) * this << " data for " << yrs << " year(s): \n";
    for (int i = 0; i < yrs; i++)
    {
        cout << "Enter year: ";
        cin >> yr[i];
        cout << "Enter bottles for that year: ";
        cin >> bot[i];
    }
    PairArray::set(yr, bot);
}

std::string &Wine::Label()
{
    return (std::string &)*this;
}

int Wine::Sum() const
{
    return PairArray::Sum();
}

void Wine::Show() const
{
    cout << "Wine: " << (const std::string) * this << "\n";
    cout << "\t\tYear\t\tBottles\n";
    PairArray::Show(yrs);
}

#endif /* __WINEC__H__ */