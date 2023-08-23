/*
@Author: mrxhar
@Date:   2023-08-22 15:46:26
@Email:  1337904145@qq.com
@Blog:
*/

#ifndef __WORKER0__H__
#define __WORKER0__H__

#include <string>

/// @brief Worker base class
class Worker
{
private:
    std::string fullname;
    long id;

public:
    Worker() : fullname("no one"), id(0L){};
    Worker(const std::string &s, long id) : fullname(s), id(id){};
    virtual ~Worker() = 0; // 纯虚
    virtual void Set();
    virtual void Show() const;
};

/// @brief Waiter succeeded to Worker
class Waiter : public Worker
{
private:
    int panache;
public:
    Waiter() : Worker(), panache(0){}
    Waiter(const std::string &s, int n, int p = 0) : Worker(), panache(p){};
    Waiter(const Worker &wk, int p = 0) : Worker(), panache(p){};
    void Set();
    void Show() const;
};

/// @brief Singer succeeded to Worker
class Singer : public Worker
{
protected:
    enum
    {
        other,
        alto,
        contralto,
        soprano,
        bass,
        baritone,
        tenor
    }; // Sound Type
    enum
    {
        Vtypes = 7
    };

private:
    static char *pv[Vtypes]; // Pointer to the appropriate style
    int voice;

public:
    Singer() : Worker(), voice(other) {}
    Singer(const std::string &s, long n, int v = other) : Worker(s, n), voice(v) {}
    Singer(const Worker &wk, int v = other) : Worker(wk), voice(v){};
    void Set();
    void Show() const;
};

#endif // __WORKER0__H__