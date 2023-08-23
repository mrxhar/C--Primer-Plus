#include <iostream>
#include "acctabc.h"

using std::cin;
using std::cout;
using std::endl;
using std::ios_base;
using std::string;

AcctABC::AcctABC(const std::string &s, long an, double bal)
{
    fullname = s;
    acctNum = an;
    balance = bal;
}

void AcctABC::Deposit(double amt)
{
    // 存款
    if (amt < 0)
    {
        cout << "Negative deposit not allowed;"
             << "deposit is cancelled.\n";
    }
    else
    {
        balance += amt;
    }
}

void AcctABC::Withdraw(double amt)
{
    balance -= amt;
}

// protected
AcctABC::Formatting AcctABC::setFormat() const
{
    Formatting f;
    f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}

void AcctABC::Restore(Formatting &f) const
{
    cout.setf(f.flag, ios_base::floatfield);
    cout.precision(f.pr);
}

///////Brass

void Brass::Withdraw(double amt)
{
    if (amt < 0)
    {
        cout << "Withdrawl amount must be positive; withdrawl canceled.\n";
    }
    else if (amt <= Balance())
    {
        AcctABC::Withdraw(amt);
    }
    else
    {
        cout << "Withdrawl amount of $" << amt << " exceeds your balance.\n"
             << "Withdraw cancelled.\n";
    }
}

void Brass::ViewAcct() const
{
    Formatting f = setFormat();
    cout << "Brass Client: " << FullName() << endl; // protested
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance: " << Balance() << endl;
    Restore(f);
}

/// BrassPlus

BrassPlus::BrassPlus(const string &s, long an, double bal, double ml, double r) : AcctABC(s, an, bal)
{
    maxLoan = ml;
    owesBank = 0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass &ba, double ml, double r) : AcctABC(ba)
{
    maxLoan = ml;
    owesBank = 0;
    rate = r;
}

void BrassPlus::ViewAcct() const
{
    Formatting f = setFormat();

    cout << "BrassPlus Client: " << FullName() << endl;
    cout << "Acoount Number: " << AcctNum() << endl;
    cout << "Balance: $" << Balance() << endl;
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout.precision(3);
    cout << "Loan Rate: " << 100 * rate << "%\n";
    Restore(f);
}

void BrassPlus::Withdraw(double amt)
{
    Formatting f = setFormat();

    double bal = Balance();

    if (amt < bal)
    {
        AcctABC::Withdraw(amt);
    }
    else if (amt <= bal * maxLoan - owesBank)
    {
        double advance = amt - bal; // 需要再借
        owesBank = advance * (1 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        AcctABC::Withdraw(amt);
    }
    else
    {
        cout << "Credit limit exceed. Trasaction cancelled.\n";
    }
    Restore(f);
}


