/*
@Author: mrxhar
@Date:   2023-08-23 14:22:05
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>

#include "emp.h"

using std::cin;
using std::cout;
using std::endl;

// abstr_emp
abstr_emp::abstr_emp() : fname("None"), lname("None"), job("None"){};
abstr_emp::abstr_emp(const std::string &fn, const std::string &ln, const std::string &j) : fname(fn), lname(ln), job(j){};
void abstr_emp::ShowAll() const
{
    cout << "fistname: " << fname << ", lname: " << lname << ", job: " << job << endl;
}
void abstr_emp::SetAll()
{
    cout << "Enter the firstname: ";
    getline(cin, fname);
    cout << "Enter the lastname: ";
    getline(cin, fname);
    cout << "Enter the job: ";
    getline(cin, job);
}
std::ostream &operator<<(std::ostream &os, const abstr_emp &e)
{
    os << e.fname << ", " << e.lname << ", " << e.job;
    return os;
}
abstr_emp::~abstr_emp(){};

// employee
employee::employee() : abstr_emp(){};
employee::employee(const std::string &fn, const std::string &ln, const std::string &j) : abstr_emp(fn, ln, j){};
void employee::ShowAll() const
{
    cout << "Employee: ";
    abstr_emp::ShowAll();
}
void employee::SetAll()
{
    cout << "Enter a employee info:  \n";
    abstr_emp::SetAll();
}

// manager

manager::manager() : abstr_emp(), inchangeof(0){};
manager::manager(const std::string &fn, const std::string &ln, const std::string &j, int ico) : abstr_emp(fn, ln, j), inchangeof(ico){};
manager::manager(const abstr_emp &e, int ico) : abstr_emp(e), inchangeof(ico){};
manager::manager(const manager &m) : abstr_emp(m)
{
    inchangeof = m.Inchargeof();
}
void manager::ShowAll() const
{
    cout << "Manager: ";
    abstr_emp::ShowAll();
    cout << "inchangeof: " << inchangeof << endl;
}
void manager::Set()
{
    cout << "Enter Manager inchangeof: ";
    cin >> inchangeof;
    while (cin.get() != '\n')
    {
        continue;
    }
}
void manager::SetAll()
{
    cout << "Enter a manager info: \n";
    abstr_emp::SetAll();
    Set();
}

// fink

fink::fink() : abstr_emp(), reportsto("None"){};
fink::fink(const std::string &fn, const std::string &ln, const std::string j, const std::string rpo) : abstr_emp(fn, ln, j), reportsto(rpo){};
fink::fink(const abstr_emp &e, const std::string rpo) : abstr_emp(e), reportsto(rpo){};
fink::fink(const fink &f): abstr_emp(f)
{
    reportsto = f.ReportsTo();
}
void fink::ShowAll() const
{
    cout << "Finl: ";
    abstr_emp::ShowAll();
    cout << "ReportsTo: " << reportsto << endl;
}
void fink::SetAll()
{
    cout << "Enter a fink info:  \n";
    abstr_emp::SetAll();
    Set();
}
void fink::Set()
{
    cout << "Enter fink ReportsTo: ";
    cin >> reportsto;
    while (cin.get() != '\n')
    {
        continue;
    }
}


//highfink

highfink::highfink() : abstr_emp(), manager(), fink(){};
highfink::highfink(const std::string &fn, const std::string &ln, const std::string &j, int ico, const std::string &rpo) : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo){};
highfink::highfink(const fink &f, int ico) : abstr_emp(f), manager(f, ico), fink(f){};
highfink::highfink(const manager &m, const std::string &rpo):abstr_emp(m),manager(m),fink(m,rpo){};
highfink::highfink(const highfink &h) : abstr_emp(h), manager(h), fink(h){};
void highfink::ShowAll()const 
{
    cout << "HighFink: ";
    abstr_emp::ShowAll();
    cout << "Inchargeof: " << manager::Inchargeof() << endl;
    cout << "ReportsTo: " << fink::ReportsTo()<< endl;
}

void highfink::SetAll()
{
    cout << "Enter a highfink info:  \n";
    abstr_emp::SetAll();
    manager::Set();
    fink::Set();
}
