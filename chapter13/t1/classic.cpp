
#include <iostream>
#include "classic.h"
#include <cstring>

Cd::Cd(const char *s1, const char *s2, int n, double x)
{
    strcpy_s(performers, 50, s1);
    strcpy_s(label, 20, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd &d)
{
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
    
    strcpy_s(performers, 50, d.performers);
    strcpy_s(label, 20, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
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