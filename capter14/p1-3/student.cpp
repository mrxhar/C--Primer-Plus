#include "studentc.h"
using std::endl;
using std::istream;
using std::ostream;
using std::string;

// public methods
double Student::Average() const
{
    if (scores.size() > 0)
    {
        return scores.sum() / scores.size();
    }
    else
    {
        return 0;
    }
}

const string Student::Name() const { return name; };

double &Student::operator[](int i)
{
    // 可以进行赋值
    return scores[i];
}

double Student::operator[](int i) const { return scores[i]; };

// private methods
ostream &Student::arr_out(std::ostream &os) const
{
    int i;
    int lim = scores.size();
    if (lim > 0)
    {
        for (i = 0; i < lim; i++)
        {
            os << scores[i] << " ";
            if (i % 5 == 4)
            {
                os << endl;
            }
        }
        if (i % 5 != 0) // 最后一行不足五个
        {
            os << endl;
        }
    }
    else
    {
        os << " empty array ";
    }
    return os;
}

// friend methods
istream &operator>>(istream &is, Student &stu)
{
    is >> stu.name;
    return is;
}

istream &getline(istream &is, Student &stu)
{
    getline(is, stu.name);
    return is;
}

ostream &operator<<(ostream &os, const Student &stu)
{
    os << "Score for " << stu.name << ":\n";
    stu.arr_out(os);
    return os;
}
