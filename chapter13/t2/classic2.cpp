
#include <iostream>
#include "classic2.h"
#include <cstring>

Cd::Cd(const char *s1, const char *s2, int n, double x)
{
    performers = new char[strlen(s1) + 1];
    strcpy_s(performers, strlen(s1) + 1, s1);

    label = new char[strlen(s2) + 1];
    strcpy_s(label, strlen(s2) + 1, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd &d)
{
    performers = new char[strlen(d.performers) + 1];
    label = new char[strlen(d.label) + 1];
    strcpy_s(performers, 50, d.performers);
    strcpy_s(label, 20, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

void Cd::Report() const
{
    std::cout << "performers: " << performers << "\nlabels: " << label << " \nselections: " << selections << "\nplaytime: " << playtime << "\n";
}

Cd& Cd::operator=(const Cd &d)
{
    if (this == &d)
    {
        return *this;
    }
    delete []performers;
    delete []label;

    performers = new char[strlen(d.performers) + 1];
    label = new char[strlen(d.label) + 1];
    strcpy_s(performers, 50, d.performers);
    strcpy_s(label, 20, d.label);

    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

Cd::~Cd(){
    delete[] performers;
    delete[] label;
}

Classic::Classic(const char *w1, char *s1, char *s2, int n, double x) : Cd(s1, s2, n, x)
{
    works = new char[strlen(w1) + 1];
    strcpy_s(works, strlen(w1) + 1, w1);
}

Classic::Classic(const char *w1, const Cd &d) : Cd(d)
{
    works = new char[strlen(w1) + 1];
    strcpy_s(works, strlen(w1) + 1, w1);
}

Classic::Classic(const Classic &c):Cd(c)
{
    works = new char[strlen(c.works) + 1];
    strcpy_s(works, strlen(c.works) + 1, c.works);
}

void Classic::Report() const
{
    // std::cout << "\nworks: " << works << "\n";
    Cd::Report();
    std::cout << "works: " << works << "\n";
}

Classic& Classic::operator=(const Classic & c)
{
    if(this == &c) return *this;
    Cd::operator=(c);
    delete[] works;
    works = new char[strlen(c.works) + 1];
    strcpy_s(works, strlen(c.works) + 1, c.works);
    return *this;
}

Classic ::~Classic() { delete[] works; }