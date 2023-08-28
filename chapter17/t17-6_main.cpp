/*
@Author: mrxhar
@Date:   2023-08-28 09:39:44
@Email:  1337904145@qq.com
@Blog:
*/
#include <iostream>
#include <fstream>
#include <string>
#include <ios>
#include "t17-6_emp.h"

const int MAX = 10;
const char *file = "staff.txt";

int main()
{
    using namespace std;
    abstr_emp *pc[MAX];

    ifstream fin;
    int classtype;
    int i = 0;
    char ch;

    // 预览内容
    fin.open(file);
    if (fin.is_open())
    {
        cout << "Here are the current contents of the " << file << " file:\n";
        while ((fin >> classtype).get(ch))
        {
            switch (classtype)
            {
            case Employee:
                pc[i] = new employee;
                break;
            case Manager:
                pc[i] = new manager;
                break;
            case Fink:
                pc[i] = new fink;
                break;
            case HighFink:
                pc[i] = new highfink;
                break;
            default:
                cerr << "Warning; Type error!\n";
                break;
            }
            pc[i]->setall(fin);
            pc[i]->ShowAll();
            i++;
        }
        fin.close();
    }


    ofstream fout(file, ios::out | ios::app);
    if (!fout.is_open())
    {
        cerr << "Can't open " << file << " file!\n";
        exit(EXIT_FAILURE);
    }

    int index = 0;
    cout << "\nPlease enter the class type of your input:\n";
    cout << "1. Employee\t2. Manager\t3. Fink\t4. HighFink\tq. Quit\n";
    while (cin >> classtype && index < MAX)
    {
        cin.ignore();
        switch (classtype)
        {
        case 1:
            pc[index] = new employee;
            pc[index]->SetAll();
            break;
        case 2:
            pc[index] = new manager;
            pc[index]->SetAll();
            break;
        case 3:
            pc[index] = new fink;
            pc[index]->SetAll();
            break;
        case 4:
            pc[index] = new highfink;
            pc[index]->SetAll();
            break;
        default:
            cerr << "Warning; Type error!\n";
            break;
        }
        index++;
        cout << "\n Please enter the class type of your input:\n";
        cout << "1. Employee\t2. Manager\t3. Fink\t4. HighFink\tq. Quit\n";
    }

    cout << "Input over. \nThank you!\n";
    cout << "Begin to write file ....\n";
    cout << "Writing..\n";
    for ( i = 0; i < index; i++)
    {
        pc[i]->writeall(fout);
    }
    fout.close();
    cout << "Writing over!\n";
    // 显示所有数据
    // 预览内容
    fin.clear();
    fin.open(file);
    if (fin.is_open())
    {
        cout << "Here are the current contents of the " << file << " file:\n";
        while ((fin >> classtype).get(ch))
        {
            switch (classtype)
            {
            case Employee:
                pc[i] = new employee;
                break;
            case Manager:
                pc[i] = new manager;
                break;
            case Fink:
                pc[i] = new fink;
                break;
            case HighFink:
                pc[i] = new highfink;
                break;
            default:
                cerr << "Warning; Type error!\n";
                break;
            }
            pc[i]->setall(fin);
            pc[i]->ShowAll();
            i++;
        }
        fin.close();
    }
}
