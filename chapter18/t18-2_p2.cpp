/*
@Author: mrxhar
@Date:   2023-08-28 16:55:58
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>
#include <string>

class Cpmv
{
public:
    struct Info
    {
        std::string gcode;
        std::string zcode;
    };

private:
    Info *pi;

public:
    Cpmv();
    Cpmv(std::string q, std::string z);
    Cpmv(const Cpmv &cp);
    Cpmv(Cpmv &&cp);
    ~Cpmv();
    Cpmv &operator=(const Cpmv &cp);
    Cpmv &operator=(Cpmv &&cp);
    Cpmv operator+(const Cpmv &obj) const;
    void Display() const;
};

Cpmv::Cpmv()
{
    pi = new Info();
    pi->gcode = "qcode";
    pi->zcode = "zcode";
}

Cpmv::Cpmv(std::string q, std::string z)
{
    pi = new Info;
    pi->gcode = q;
    pi->zcode = z;
}

Cpmv::Cpmv(const Cpmv &cp)
{
    // 复制构造函数
    pi = new Info();
    pi->gcode = cp.pi->gcode;
    pi->zcode = cp.pi->zcode;
}

Cpmv::Cpmv(Cpmv &&cp)
{
    pi = cp.pi;
    cp.pi = nullptr;
}

Cpmv::~Cpmv()
{
    delete pi;
}

Cpmv &Cpmv ::operator=(const Cpmv &cp)
{
    if (this == &cp)
    {
        return *this;
    }
    delete pi;
    pi = new Info;
    pi->gcode = cp.pi->gcode;
    pi->zcode = cp.pi->zcode;
    return *this;
}

Cpmv &Cpmv::operator=(Cpmv &&cp)
{
    if (this == &cp)
    {
        return *this;
    }
    delete pi;
    pi = cp.pi;
    cp.pi = nullptr;
    return *this;
}

Cpmv Cpmv::operator+(const Cpmv &obj) const
{
    Cpmv temp;
    temp.pi->gcode = pi->gcode + obj.pi->gcode;
    temp.pi->zcode = pi->zcode + obj.pi->zcode;
    return temp;
}

void Cpmv::Display() const
{
    std::cout << pi->gcode << ", " << pi->zcode << "\n";
}

int main()
{
    Cpmv cp1("sdad", "das");
    cp1.Display();
    Cpmv cp2 = cp1 + Cpmv("no1", "no2");
    cp2.Display();
    Cpmv cp3(cp1 + cp2);
    cp3.Display();
    return 0;
}
