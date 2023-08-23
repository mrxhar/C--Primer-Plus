#ifndef __DAM3__H__
#define __DAM3__H__

#include <iostream>

class DMAABC
{
private:
    char *label;
    int rating;
protected:
    const char *getLabel() const { return label; }
    int getRating() const { return rating; }
public:
    DMAABC(const char *l = "null", int r = 0);
    DMAABC(const DMAABC& other);
    virtual ~DMAABC();
    DMAABC &operator=(const DMAABC &other);
    virtual void View() const = 0; // 纯虚函数 可以不实现
};

class baseDMA : public DMAABC
{
public:
    baseDMA(const char *l = "null", int r = 0):DMAABC(l, r) {};
    baseDMA(const baseDMA &rs) : DMAABC(rs){};
    virtual ~baseDMA(){};
    virtual void View() const;
    baseDMA &operator=(const baseDMA &rs);
    friend std::ostream &operator<<(std::ostream &out, const baseDMA &rs);
};

class lacksDMA : public DMAABC
{
private:
    enum
    {
        COL_lEN = 40
    };
    char color[COL_lEN]; // 没有使用指针
public:
    lacksDMA(const char *c = "blank", const char *l = "null", int r = 0);
    lacksDMA(const char *c, const DMAABC &rc);
    lacksDMA(const lacksDMA &ls);
    virtual void View() const;
    friend std::ostream &operator<<(std::ostream &os, const lacksDMA &rs);
};

class hasDMA : public DMAABC
{
private:
    char *style;

public:
    hasDMA(const char *s = "none", const char *l = "none", int r = 0);
    hasDMA(const char *s, const DMAABC &rs);
    hasDMA(const hasDMA &hs); // 复制构造函数
    ~hasDMA();
    hasDMA &operator=(const hasDMA &rs); // 赋值函数
    virtual void View() const;
    friend std::ostream &operator<<(std::ostream &os, const hasDMA &hs);
};

#endif /* __DAM3__H__ */