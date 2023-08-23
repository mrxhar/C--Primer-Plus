/*
@Author: mrxhar
@Date:   2023-08-22 16:50:19
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>
#include "workermi.h"

using std::cin;
using std::cout;
using std::endl;

// Worker methods

Worker::~Worker(){};

void Worker::Set()
{
    cout << "Enter worker's name:";
    getline(cin, fullname);
    cout << "Enter worker's ID: ";
    cin >> id;
    while (cin.get() != '\n')
    {
        continue;
    }
}

void Worker::Show() const
{
    cout << "Name: " << fullname << "\nEmployee ID: " << id << "\n";
}

void Worker::Data() const
{
    cout << "Name: " << fullname << "\nEmployee ID: " << id << "\n";
}

void Worker::Get()
{
    getline(cin, fullname);
    cout << "Enter worker's ID: ";
    cin >> id;
    while (cin.get() != '\n')
    {
        continue;
    }
}

/// Waiter methods

void Waiter::Data() const
{
    cout << "Panache rating: " << panache << "\n";
}

void Waiter::Set()
{
    cout << "Enter waiter's name: ";
    Worker::Get();
    Get();
}

void Waiter::Get()
{
    cout << "Enter waiter's panache rating: ";
    cin >> panache;
    while (cin.get() != '\n')
    {
        continue;
    }
}

void Waiter::Show() const
{
    cout << "Category; waiter\n";
    Worker::Data();
    Data();
}

// Singer methods
char *Singer::pv[] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"}; // static variables

void Singer::Data() const
{
    cout << "Vocal range: " << pv[voice] << "\n";
}

void Singer::Get()
{
    cout << "Enter number for singer's vocal range:\n";
    int i;
    for (i = 0; i < Vtypes; i++)
    {
        cout << i << ": " << pv[i] << "   ";
        if (i % 4 == 3)
        {
            cout << endl;
        }
    }
    if (i % 4 == 0)
    {
        cout << endl;
    }
    // 重新输入
    while (cin >> voice && (voice < 0 || voice >= Vtypes))
    {
        cout << "Please enter a value >= 0 and < " << Vtypes << endl;
    }

    while (cin.get() != '\n')
    {
        continue;
    }
}

void Singer::Set()
{
    cout << "Enter singer's name: ";
    Worker::Get();
    Get();
}

void Singer::Show() const
{
    cout << "Category: singer" << endl;
    Worker::Data();
    Data();
}

void SingingWaiker::Data() const
{
    Singer::Data();
    Waiter::Data();
}

void SingingWaiker::Get()
{
    Waiter::Get();
    Singer::Get();
}

void SingingWaiker::Set()
{
    cout << "Enter singing waiter's name: ";
    Worker::Get();
    Get();
}

void SingingWaiker::Show() const
{
    cout << "Category: singing waiter" << endl;
    Worker::Data();
    Data();
}

