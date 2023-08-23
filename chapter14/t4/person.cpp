/*
@Author: mrxhar
@Date:   2023-08-23 11:08:42
@Email:  1337904145@qq.com
@Blog:   
*/

#include <iostream>
#include "Person.h"

using std::cout;
using std::endl;

Person::Person(const Person& p)
{
    firstname = p.firstname;
    lastname = p.lastname;
}

Person::~Person()
{

}

void Person::Show() const
{
    cout << "First name: " << firstname << " Last name: " << lastname << endl;
}

Gunslinger::Gunslinger(const Gunslinger &g):Person(g)
{
    notch = g.notch;
    time = g.time;
}

Gunslinger::~Gunslinger()
{

}

double Gunslinger::Draw() const
{
    return time;
}

void Gunslinger::Show() const
{
    cout << "category: Gunslinger" << endl;
    Person::Show();
    cout << "Nick: " << notch << " , Gun out time: " << time << endl;
}

PokerPlayer::~PokerPlayer()
{

}

int PokerPlayer::Draw() const
{
    return (rand() % 52);
}

void PokerPlayer::Show() const
{
    cout << "category: PockerPlayer " << endl;
    Person::Show();
}

BadDude::~BadDude()
{

}
void BadDude::Show() const
{
    cout << "Category: BadDude" << endl;
    Gunslinger::Show();
    cout << "next card: " << PokerPlayer::Draw() << endl;
} 

int BadDude::Cdraw() 
{
    return PokerPlayer::Draw();
}

double BadDude::Gdraw() 
{
    return Gunslinger::Draw();
}
