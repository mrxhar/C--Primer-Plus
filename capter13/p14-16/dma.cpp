#include "dma.h"
#include <cstring>


using std::strlen;

baseDMA::baseDMA(const char * l,int r)
{
    label = new char[strlen(l) + 1];
    strcpy_s(label, strlen(l) + 1, l);
    rating = r;
}

baseDMA::baseDMA(const baseDMA & rs)
{
    //
    label = new char[strlen(rs.label) + 1];
    strcpy_s(label,strlen(rs.label) + 1,rs.label);
    rating = rs.rating;
}

baseDMA::~baseDMA()
{
    delete label;
}

baseDMA& baseDMA::operator=(const baseDMA &rs)
{
    if (this == &rs)
    {
        return *this;
    }
    label = new char[strlen(rs.label) + 1];
    strcpy_s(label, strlen(rs.label) + 1, rs.label);
    rating = rs.rating;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const baseDMA &rs)
{
    out << "Label: " << rs.label << std::endl;
    out << "Rating: " << rs.rating << std::endl;
    return out;
}

//lacksDMA
lacksDMA::lacksDMA(const char *c, const char *l, int r) : baseDMA(l,r)
{
    strcpy_s(color, COL_lEN, c);
    color[COL_lEN - 1] = '\0';
}

lacksDMA::lacksDMA(const char *c,const baseDMA &rs):baseDMA(rs)
{
    strcpy_s(color, COL_lEN, c);
    color[COL_lEN - 1] = '\0';
}

std::ostream &operator<<(std::ostream &os, const lacksDMA &ls)
{
    os << (const baseDMA &)ls;
    os << "Color: " << ls.color << std::endl;
    return os;
}

// hasMDA

hasDMA::hasDMA(const char *s, const char *l,int r) : baseDMA(l,r)
{
    style = new char[strlen(s) + 1];
    strcpy_s(style, strlen(s) + 1, s);
}

hasDMA::hasDMA(const char *s, const baseDMA &rs) :baseDMA(rs)
{
    style = new char[strlen(s) + 1];
    strcpy_s(style, strlen(s) + 1, s);
}
hasDMA::hasDMA(const hasDMA& hs) : baseDMA(hs)
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
    
    baseDMA::operator=(hs); // 使用基类的 = 赋值运算符
    delete[] style;
    style = new char[strlen(hs.style) + 1];
    strcpy_s(style, (strlen(hs.style) + 1), hs.style);
    return *this;
}

std::ostream& operator<<(std::ostream &os, const hasDMA &hs)
{
    os << (const baseDMA &)hs;
    os << "Style: " << hs.style << std::endl;
    return os;
}