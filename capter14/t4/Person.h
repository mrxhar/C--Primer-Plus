

/*
@Author: mrxhar
@Date:   2023-08-23 10:17:53
@Email:  1337904145@qq.com
@Blog:
*/
#ifndef __PERSON__H__
#define __PERSON__H__

#include <iostream>

class Person
{
private:
    std::string firstname;
    std::string lastname;

public:
    Person(const std::string &f, const std::string &l) : firstname(f), lastname(l){};
    Person() : firstname("None"), lastname("None"){};
    Person(const Person &p);
    virtual ~Person() = 0; // 
    virtual void Show() const = 0;
};

class Gunslinger : virtual public Person
{
private:
    int notch;
    double time;

public:
    // cosntructor
    Gunslinger(int n = 0, double t = 0) : time(t), Person(), notch(n){};
    Gunslinger(const std::string &f, const std::string &l, int n, double t) : time(t), notch(n), Person(f, l){};
    Gunslinger(const Person &p, int n = 0, double t = 0) : Person(p), notch(n), time(t){};
    Gunslinger(const Gunslinger &g);
    ~Gunslinger();
    double Draw() const;
    void Show() const;
};

class PokerPlayer : virtual public Person
{
public:
    int Draw() const;
    void Show() const;
    PokerPlayer() : Person(){};
    PokerPlayer(const Person &p) : Person(p){};
    PokerPlayer(const std::string &f, const std::string &l) : Person(f, l){};
    PokerPlayer(const PokerPlayer &p) : Person(p){};
    ~PokerPlayer();
};

class BadDude : public Gunslinger, public PokerPlayer
{
private:
public:
    BadDude(){};
    BadDude(const std::string &f, const std::string &l, int n, double t) : Person(f, l), Gunslinger(f, l, n, t), PokerPlayer(f, l){};
    BadDude(const Person &p, int n, double t) : Person(p), Gunslinger(p, n, t), PokerPlayer(p){};
    BadDude(const Gunslinger &g) : Person(g),Gunslinger(g),PokerPlayer(g){};
    BadDude(const PokerPlayer &p, int n, double t) : Person(p), Gunslinger(p, n, t), PokerPlayer(p){};
    BadDude(const BadDude &b): Person(b), PokerPlayer(b),Gunslinger(b){};
    ~BadDude();
    void Show() const;
    double Gdraw();
    int Cdraw();
};

#endif /* __PERSON__H__ */