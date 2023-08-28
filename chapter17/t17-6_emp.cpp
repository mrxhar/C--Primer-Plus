/*
@Author: mrxhar
@Date:   2023-08-28 09:14:45
@Email:  1337904145@qq.com
@Blog:
*/
#include <iostream>
#include <string>
#include "t17-6_emp.h"

using std::cin;
using std::cout;
using std::endl;

abstr_emp::abstr_emp()
{
    fname = "None";
    lname = "None";
    job = "None";
}

void abstr_emp::ShowAll() const
{
    cout << "First Name: " << fname << "\n";
    cout << "Last Name: " << lname << "\n";
    cout << "Job: " << job << "\n";
}

void abstr_emp::SetAll()
{
    cout << "Enter first name: ";
    getline(cin, fname);
    cout << "Enter last name: ";
    getline(cin, lname);
    cout << "Enter job: ";
    getline(cin, job);
}

void abstr_emp::setall(std::ifstream &fin)
{
    getline(fin, fname);
    getline(fin, lname);
    getline(fin, job);
}

void abstr_emp::writeall(std::ofstream &fout)
{
    fout << fname << endl
         << lname << endl
         << job << endl;
}

std::ostream &operator<<(std::ostream &os, const abstr_emp &e)
{
    os << endl;
    os << "First Name: " << e.fname << "\n";
    os << "Last Name: " << e.lname << "\n";
    return os;
}
abstr_emp::~abstr_emp() {}

/// employee

employee::employee() : abstr_emp(){};
void employee::ShowAll() const
{
    cout << "\nEmployee:\n";
    abstr_emp::ShowAll();
}
void employee::SetAll()
{
    cout << "Employee: \n";
    abstr_emp::SetAll();
}
void employee::setall(std::ifstream &fin)
{
    abstr_emp::setall(fin);
}
void employee::writeall(std::ofstream &fout)
{
    fout << Employee << endl;
    abstr_emp::writeall(fout);
}

/// manager

manager::manager() : abstr_emp()
{
    inchargeof = 0;
}
void manager::ShowAll() const
{
    cout << "\nManager:\n";
    abstr_emp::ShowAll();
    cout << "In charge of: " << inchargeof << endl;
}

void manager::SetAll()
{
    cout << "Manager: \n";
    abstr_emp::SetAll();
    cout << "In charge of: ";
    cin >> inchargeof;
}

void manager::setall(std::ifstream &fin)
{
    abstr_emp::setall(fin);
    fin >> inchargeof;
    fin.ignore(); //
};

void manager::writeall(std::ofstream &fout)
{
    fout << Manager << endl;
    abstr_emp::writeall(fout);
    fout << inchargeof << endl;
}


/// fink

fink::fink() : abstr_emp()
{
    reportsto = "None";
}
void fink::ShowAll() const
{
    cout << "\nFink:\n";
    abstr_emp::ShowAll();
    cout << "Reports to: " << reportsto << endl;
}
void fink::SetAll()
{
    cout << "Fink: \n";
    abstr_emp::SetAll();
    cout << "Reports to: ";
    getline(cin, reportsto);
}

void fink::setall(std::ifstream &fin)
{
    abstr_emp::setall(fin);
    getline(fin, reportsto);
    fin.ignore(); //
};

void fink::writeall(std::ofstream &fout)
{
    fout << Fink << endl;
    abstr_emp::writeall(fout);
    fout << reportsto << endl;
}


highfink::highfink() : abstr_emp(), manager(), fink(){};
void highfink::ShowAll() const
{
    cout << "\nHighfink:\n";
    abstr_emp::ShowAll();
    cout << "Reports to: " << fink::Reportsto() << endl;
    cout << "In charge of: " << manager::Inchargeof() << endl;
}

void highfink::SetAll()
{
    cout << "Highfink: \n";
    abstr_emp::SetAll();
    cout << "Reports to: ";
    cin >> fink::Reportsto();
    cout << "In charge of: ";
    cin >> manager::Inchargeof();
    cin.ignore();
}
void highfink::setall(std::ifstream &fin)
{
    abstr_emp::setall(fin);
    fin >> manager::Inchargeof();
    fin.ignore();
    getline(fin, fink::Reportsto());
    fin.ignore();
}

void highfink::writeall(std::ofstream &fout)
{
    fout << HighFink << endl;
    abstr_emp::writeall(fout);
    fout << fink::Reportsto() << endl;
    fout << manager::Inchargeof() << endl;
}