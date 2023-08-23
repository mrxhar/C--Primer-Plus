/*
@Author: mrxhar
@Date:   2023-08-22 16:39:41
@Email:  1337904145@qq.com
@Blog:
*/

#ifndef __WORKERMI__H__
#define __WORKERMI__H__

#include <string>

/// @brief Worker base class
class Worker
{
private:
    std::string fullname;
    long id;

protected:
    virtual void Data() const;
    virtual void Get();

public:
    Worker() : fullname("no one"), id(0L){};
    Worker(const std::string &s, long id) : fullname(s), id(id){};
    virtual ~Worker() = 0; // 纯虚
    virtual void Set() = 0;
    virtual void Show() const = 0;
};

/// @brief Waiter succeeded to Worker
class Waiter : virtual public Worker
{
private:
    int panache;

protected:
    void Data() const;
    void Get();

public:
    Waiter() : Worker(), panache(0) {}
    Waiter(const std::string &s, int n, int p = 0) : Worker(), panache(p){};
    Waiter(const Worker &wk, int p = 0) : Worker(), panache(p){};
    void Set();
    void Show() const;
};

/// @brief Singer succeeded to Worker
class Singer : virtual public Worker
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
    void Data() const;
    void Get();

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

class SingingWaiker : public Singer, public Waiter
{
protected:
    void Data() const;
    void Get();

public:
    SingingWaiker(){};

    SingingWaiker(const std::string &s, long n, int p = 0, int v = other) : Worker(s, n), Waiter(s, n, p), Singer(s, n, v){};
    SingingWaiker(const Worker &wk, int p = 0, int v = other) : Worker(wk), Waiter(wk, p), Singer(wk, v){};
    SingingWaiker(const Waiter &wt, int v = other) : Worker(wt), Waiter(wt), Singer(wt, v){};
    SingingWaiker(const Singer &si, int p = 0) : Worker(si), Waiter(si, p), Singer(si){};

    void Set();
    void Show() const;
};

#endif /* __WORKERMI__H__ */