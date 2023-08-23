/*
@Author: mrxhar
@Date:   2023-08-23 14:04:36
@Email:  1337904145@qq.com
@Blog:
*/
#ifndef __EMP__H__
#define __EMP__H__

#include <iostream>
#include <string>

class abstr_emp
{
private:
    std::string fname;
    std::string lname;
    std::string job;

public:
    abstr_emp();
    abstr_emp(const std::string &fn, const std::string &ln, const std::string &j);
    virtual void ShowAll() const;
    virtual void SetAll();
    friend std::ostream &operator<<(std::ostream &os, const abstr_emp &);
    virtual ~abstr_emp();
};

class employee : public abstr_emp
{
public:
    employee();
    employee(const std::string &fn, const std::string &ln, const std::string &j);
    virtual void ShowAll() const;
    virtual void SetAll();
};

class manager : virtual public abstr_emp
{
private:
    int inchangeof;

protected:
    int Inchargeof() const { return inchangeof; }
    int &Inchargeof() { return inchangeof; }

public:
    manager();
    manager(const std::string &fn, const std::string &ln, const std::string &j, int ico = 0);
    manager(const abstr_emp &e, int ico);
    manager(const manager &m);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void Set();
};

class fink : virtual public abstr_emp
{
private:
    std::string reportsto;

protected:
    const std::string ReportsTo() const { return reportsto; }
    std::string &ReportsTo() { return reportsto; }

public:
    fink();
    fink(const std::string &fn, const std::string &ln, const std::string j, const std::string rpo);
    fink(const abstr_emp &e, const std::string rpo);
    fink(const fink &f);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void Set();
};

class highfink : public manager, public fink
{
public:
    highfink();
    highfink(const std::string &fn, const std::string &ln, const std::string &j, int ico, const std::string &rpo);
    highfink(const fink &f, int ico);
    highfink(const manager &m, const std::string &rpo);
    highfink(const highfink &h);
    virtual void ShowAll() const;
    virtual void SetAll();
};

#endif /*__EMP__H__*/