/*
@Author: mrxhar
@Date:   2023-08-24 17:23:22
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;

class Grand
{
private:
    int hold;

public:
    Grand(int hold = 0) : hold(hold){};
    virtual void Speak() const { cout << "I am a grand class !\n"; }
    virtual int Value() const { return hold; }
};

class Superb : public Grand
{
public:
    Superb(int hold = 0) : Grand(hold){};
    void Speak() const { cout << "I am a superb class !\n"; }
    virtual void Say() const { cout << "I hold the superb value of " << Value() << "!\n"; }
};

class Magnificent : public Superb
{
private:
    char ch;

public:
    Magnificent(int h = 0, char c = 'A') : ch(c), Superb(h) {}
    void Speak() const { cout << "I am a magnificent class!!!\n"; }
    void Say() const
    {
        cout << "I hold the character " << ch << " and the integer " << Value() << "!\n";
    }
};

Grand *GetOne();

int main()
{
    std::srand(std::time(0));

    Grand *pg;
    Superb *ps;

    for (int i = 0; i < 100; i++)
    {
        pg = GetOne();
        pg->Speak();
        if (ps = dynamic_cast<Superb *>(pg))
        {
            ps->Say();
        }
        cout << "\n";
    }
    return 0;
}

Grand *GetOne()
{
    Grand *p;
    switch (std::rand() % 3)
    {
    case 0:
        p = new Grand(std::rand() % 100);
        break;
    case 1:
        p = new Superb(std::rand() % 100);
        break;
    case 2:
        p = new Magnificent(std::rand() % 100, 'A' + std::rand() % 26);
        break;
    }
    return p;
}