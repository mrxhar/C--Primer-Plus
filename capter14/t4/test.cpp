// test.cpp -- check the functions and classes
#include <iostream>
#include <string>
#include "person.h"
#include <time.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

int main()
{
    srand(time(0));
    const int SIZE = 4;

    Person *p[SIZE];
    int i;
    for (i = 0; i < SIZE; i++)
    {
        char flag;
        cout << "Enter the person category:\n"
             << "g: Gunslinger  p: PokerPlayer  b: BadDude  q: Quit\n";
        cin >> flag;
        cin.ignore();
        while (strchr("gpbq", flag) == NULL)
        {
            cout << "Please enter a g, p, b, or q: ";
            cin >> flag;
            cin.ignore();
        }
        if (flag == 'q')
        {
            break;
        }
        string fname;
        string lname;
        int n = 0;
        double t = 0;
        cout << "Please enter the first name: ";
        getline(cin, fname);
        cout << "Please enter the last name: ";
        getline(cin, lname);
        switch (flag)
        {
        case 'g':
            cout << "Please enter the nicks: ";
            cin >> n;
            cout << "Please enter the \"Gun Out\" time: ";
            cin >> t;
            p[i] = new Gunslinger(fname, lname, n, t);
            break;
        case 'p':
            p[i] = new PokerPlayer(fname, lname);
            break;
        case 'b':
            cout << "Please enter the nicks: ";
            cin >> n;
            cout << "Please enter the \"Gun Out\" time: ";
            cin >> t;
            p[i] = new BadDude(fname, lname, n, t);
            break;
        }
    }
    cout << "\nHere is your person:\n";
    int j;
    for (j = 0; j < i; j++)
    {
        cout << endl;
        p[j]->Show();
    }
    for (j = 0; j < i; j++)
        delete p[j];
    cout << "Bye\n";
    system("pause");
    return 0;
}