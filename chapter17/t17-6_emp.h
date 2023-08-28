/*
@Author: mrxhar
@Date:   2023-08-28 08:56:34
@Email:  1337904145@qq.com
@Blog:
*/
#ifndef __T17_6_EMP__H__
#define __T17_6_EMP__H__

#include <iostream>
#include <string>
#include <fstream>
using std::string;

enum classkind
{
    Zero,
    Employee,
    Manager,
    Fink,
    HighFink
};

class abstr_emp
{
private:
    string fname;
    string lname;
    string job;

public:
    abstr_emp();
    abstr_emp(const string &fn, const string &ln, const string &j) : fname(fn), lname(ln), job(j){};
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void setall(std::ifstream &fin);
    virtual void writeall(std::ofstream &fout);
    friend std::ostream &operator<<(std::ostream &os, const abstr_emp &e);
    virtual ~abstr_emp() = 0;
};

class employee : public abstr_emp
{
public:
    employee();
    employee(const string &fn, const string &ln, const string &j) : abstr_emp(fn, ln, j){};
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void setall(std::ifstream &fin);
    virtual void writeall(std::ofstream &fout);
};

class manager : virtual public abstr_emp
{
private:
    int inchargeof;

protected:
    int Inchargeof() const { return inchargeof; };
    int &Inchargeof() { return inchargeof; };

public:
    manager();
    manager(const string &fn, const string &ln, const string &j, int i) : abstr_emp(fn, ln, j), inchargeof(i){};
    manager(const abstr_emp &e, const int iconst) : abstr_emp(e), inchargeof(iconst){};
    manager(const manager &m) : abstr_emp(m), inchargeof(m.inchargeof){};
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void setall(std::ifstream &fin);
    virtual void writeall(std::ofstream &fout);
};

class fink : virtual public abstr_emp
{
private:
    string reportsto;

protected:
    string Reportsto() const { return reportsto; };
    string &Reportsto() { return reportsto; };

public:
    fink();
    fink(const string &fn, const string &ln, const string &j, const string &r) : abstr_emp(fn, ln, j), reportsto(r){};
    fink(const abstr_emp &e, const string &r) : abstr_emp(e), reportsto(r){};
    fink(const fink &f) : abstr_emp(f), reportsto(f.reportsto){};
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void setall(std::ifstream &fin);
    virtual void writeall(std::ofstream &fout);
};

class highfink : public manager, public fink
{
public:
    highfink();
    highfink(const string &fn, const string &ln, const string &j, const string &r, int i) : abstr_emp(fn, ln, j), manager(fn, ln, j, i), fink(fn, ln, j, r){};
    highfink(const abstr_emp &e, const string &r, int i) : abstr_emp(e), manager(e, i), fink(e, r){};
    highfink(const highfink &h) : abstr_emp(h), manager(h), fink(h) {}
    highfink(const fink &f, int i) : abstr_emp(f), manager(f, i), fink(f){};
    highfink(const manager &m, const string &r) : abstr_emp(m), manager(m), fink(m, r){};
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void setall(std::ifstream &fin);
    virtual void writeall(std::ofstream &fout);
};

#endif /*__T17_6_EMP__H__*/