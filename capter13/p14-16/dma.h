#ifndef __DAM__H__
#define __DAM__H__

#include <iostream>

class baseDMA
{
private:
    char *label;
    int rating;

public:
    baseDMA(const char *l = "null", int r = 0);
    baseDMA(const baseDMA &rs);
    virtual ~baseDMA();
    baseDMA &operator=(const baseDMA &rs);
    friend std::ostream &operator<<(std::ostream &out, const baseDMA &rs);
};

class lacksDMA : public baseDMA
{
private:
    enum
    {
        COL_lEN = 40
    };
    char color[COL_lEN]; // 没有使用指针
public:
    lacksDMA(const char *c = "blank", const char *l = "null", int r = 0);
    lacksDMA(const char *c, const baseDMA &rc);
    friend std::ostream &operator<<(std::ostream &os, const lacksDMA &rs);
};

class hasDMA : public baseDMA
{
private:
    char *style;

public:
    hasDMA(const char *s = "none", const char *l = "none", int r = 0);
    hasDMA(const char *s, const baseDMA &rs);
    hasDMA(const hasDMA &hs); // 复制构造函数
    ~hasDMA();
    hasDMA &operator=(const hasDMA &rs); // 赋值函数
    friend std::ostream &operator<<(std::ostream &os, const hasDMA &hs);
};

#endif /* __DAM__H__ */