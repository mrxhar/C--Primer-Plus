/*
@Author: mrxhar
@Date:   2023-08-28 10:41:25
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>
#include <utility>

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
    Useless &operator=(const Useless &f);
    Useless &operator=(Useless &&f);
    void ShowDate() const;
};

int Useless::ct = 0;

Useless::Useless()
{
    ++ct; // 个数
    n = 0;
    pc = nullptr;
    ShowObject();
}

Useless::Useless(int k) : n(k)
{
    ++ct;
    pc = new char[n];
    ShowObject();
}

Useless::Useless(int k, char ch) : n(k)
{
    ++ct;
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
    pc = f.pc;      // 窃取地址
    f.pc = nullptr; // 原有对象置空，以防影响新对象
    f.n = 0;
    ShowObject();
}
Useless::~Useless()
{
    delete[] pc;
}

Useless Useless::operator+(const Useless &f)
{
    Useless temp(n + f.n);
    for (int i = 0; i < n; i++)
    {
        temp.pc[i] = pc[i];
    }
    for (int i = n; i < temp.n; i++)
    {
        temp.pc[i] = f.pc[i - n];
    }
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

Useless &Useless::operator=(const Useless &f)
{
    cout << "copy assigment operator called:\n";
    if (this == &f)
    {
        return *this;
    }
    delete[] pc;
    n = f.n;
    pc = new char[n];
    for (int i = 0; i < n; i++)
    {
        pc[i] = f.pc[i];
    }
    return *this;
}

Useless &Useless::operator=(Useless &&f)
{
    cout << "move assignment operator called:\n";
    if (this == &f)
    {
        return *this;
    }
    delete[] pc;
    n = f.n;
    pc = f.pc;
    f.n = 0;
    f.pc = nullptr;
    return *this;
}

int main()
{
    {
        Useless one(10, 'x');
        Useless two = one + one; // 赋值构造 =
        cout << "object one ";
        one.ShowDate();
        cout << "object two ";
        two.ShowDate();

        Useless three, four;
        cout << "three = one\n";
        three = one;
        cout << "now object three =  ";
        three.ShowDate();
        cout << "and object one = ";
        one.ShowDate();

        cout << "four = one + two\n";
        four = one + two;
        cout << "now object four = ";
        four.ShowDate();

        cout << "four = move(one)\n";
        four = std::move(one);
        cout << "now object four = ";
        four.ShowDate();
        cout << "and object one = ";
        one.ShowDate();
    }
    return 0;
}
