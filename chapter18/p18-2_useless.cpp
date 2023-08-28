/*
@Author: mrxhar
@Date:   2023-08-28 10:41:25
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>

using namespace std;

class Useless
{
private:
    int n;
    char *pc;
    static int ct;
    void ShowObject() const;

public:
    Useless();
    explicit Useless(int k);
    Useless(int k, char ch);
    Useless(const Useless &f);
    Useless(Useless &&f); // 移动构造函数
    ~Useless();
    Useless operator+(const Useless &f);
    void ShowDate() const;
};

int Useless::ct = 0;

Useless::Useless()
{
    ++ct; // 个数
    n = 0;
    pc = nullptr;
    cout << "default constructor called; number of objects: " << ct << endl;
    ShowObject();
}

Useless::Useless(int k) : n(k)
{
    ++ct;
    cout << "int constructor called; number of objects: " << ct << endl;
    pc = new char[n];
    ShowObject();
}

Useless::Useless(int k, char ch) : n(k)
{
    ++ct;
    cout << "int ,char constructor called; number of objects: " << ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; i++)
    {
        pc[i] = ch;
    }
    ShowObject();
}

Useless::Useless(const Useless &f) : n(f.n)
{
    ++ct;
    cout << "copy constructor called; number of objects: " << ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; i++)
    {
        pc[i] = f.pc[i];
    }
    ShowObject();
}
Useless::Useless(Useless &&f) : n(f.n)
{
    ++ct;
    cout << "move constructor called; number of objects: " << ct << endl;
    pc = f.pc;      // 窃取地址
    f.pc = nullptr; // 原有对象置空，以防影响新对象
    f.n = 0;
    ShowObject();
}
Useless::~Useless()
{
    cout << "destructor called; number of objects: " << --ct << endl;
    cout << "delete object:\n";
    ShowObject();
    delete[] pc;
}

Useless Useless::operator+(const Useless &f)
{
    cout << "Entering operator+()\n";
    Useless temp(n + f.n);
    for (int i = 0; i < n; i++)
    {
        temp.pc[i] = pc[i];
    }
    for (int i = n; i < temp.n; i++)
    {
        temp.pc[i] = f.pc[i - n];
    }

    cout << "temp object:\n";
    cout << "Leaving operator+()\n";
    return temp;
}

void Useless::ShowObject() const
{
    cout << "Number of element: " << n;
    cout << " Data address: " << (void *)pc << endl;
}
void Useless::ShowDate() const
{
    if (n == 0)
    {
        cout << "(Object empty)";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << pc[i];
        }
    }
    cout << endl;
}

int main()
{
    {
        Useless one(10, 'x');
        Useless two = one;// 赋值构造
        Useless three(20, 'o');
        Useless four(one + three);// 移动构造，加法过程中会产生一个临时对象
        cout << "object one ";
        one.ShowDate();
        cout << "object two ";
        two.ShowDate();
        cout << "object three ";
        three.ShowDate();
        cout << "object four ";
        four.ShowDate();
    }
    return 0;
}
