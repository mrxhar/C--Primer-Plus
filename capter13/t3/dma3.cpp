#include "dma3.h"
#include <cstring>


using std::strlen;


DMAABC::DMAABC(const char *l,int r)
{
    label = new char[strlen(l) + 1];
    strcpy_s(label, strlen(l) + 1, l);
    rating = r;
}

DMAABC::DMAABC(const DMAABC& other)
{
    label = new char[strlen(other.label) + 1];
    strcpy_s(label, strlen(other.label) + 1, other.label);
    rating = other.rating;
}


DMAABC::~DMAABC()
{
    delete[] label;
}


DMAABC& DMAABC::operator=(const DMAABC& other)
{
    if (this == &other)
    {
        return *this;
    }
    label = new char[strlen(other.label) + 1];
    strcpy_s(label, strlen(other.label) + 1, other.label);
    rating = other.rating;
    return *this;
}


baseDMA& baseDMA::operator=(const baseDMA &rs)
{
    if (this == &rs)
    {
        return *this;
    }
    DMAABC::operator=(rs);
    return *this;
}

void baseDMA::View() const{
    std::cout << "Label: " << getLabel() << std::endl;
    std::cout << "Rating: " << getRating() << std::endl;
}

std::ostream &operator<<(std::ostream &out, const baseDMA &rs)
{
    out << "Label: " << rs.getLabel() << std::endl;
    out << "Rating: " << rs.getRating() << std::endl;
    return out;
}

//lacksDMA
lacksDMA::lacksDMA(const char *c, const char *l, int r) : DMAABC(l, r)
{
    strcpy_s(color, COL_lEN, c);
    color[COL_lEN - 1] = '\0';
}

lacksDMA::lacksDMA(const char *c, const DMAABC &rs) : DMAABC(rs)
{
    strcpy_s(color, COL_lEN, c);
    color[COL_lEN - 1] = '\0';
}

lacksDMA::lacksDMA(const lacksDMA &ls) : DMAABC(ls)
{
    strcpy_s(color, COL_lEN, ls.color);
}

void lacksDMA::View() const
{
    std::cout << "Label: " << getLabel() << std::endl;
    std::cout << "Rating: " << getRating() << std::endl;
    std::cout << "Color: " << color << std::endl;
}

std::ostream &operator<<(std::ostream &os, const lacksDMA &ls)
{
    os << (const baseDMA &)ls;
    os << "Color: " << ls.color << std::endl;
    return os;
}

// hasMDA

hasDMA::hasDMA(const char *s, const char *l, int r) : DMAABC(l, r)
{
    style = new char[strlen(s) + 1];
    strcpy_s(style, strlen(s) + 1, s);
}

hasDMA::hasDMA(const char *s, const DMAABC &rs) : DMAABC(rs)
{
    style = new char[strlen(s) + 1];
    strcpy_s(style, strlen(s) + 1, s);
}
hasDMA::hasDMA(const hasDMA &hs) : DMAABC(hs)
{
    style = new char[strlen(hs.style) + 1];
    strcat_s(style, strlen(hs.style) + 1, hs.style);
}

hasDMA::~hasDMA()
{
    delete[] style;
}

hasDMA& hasDMA::operator=(const hasDMA&hs)
{
    if (this == &hs)
    {
        return *this;
    }

    DMAABC::operator=(hs); // 使用基类的 = 赋值运算符
    delete[] style;
    style = new char[strlen(hs.style) + 1];
    strcpy_s(style, (strlen(hs.style) + 1), hs.style);
    return *this;
}

void hasDMA::View()const
{
    std::cout << "Label: " << getLabel() << std::endl;
    std::cout << "Rating: " << getRating() << std::endl;
    std::cout << "Style: " << style << std::endl;
}

std::ostream& operator<<(std::ostream &os, const hasDMA &hs)
{
    os << (const baseDMA &)hs;
    os << "Style: " << hs.style << std::endl;
    return os;
}