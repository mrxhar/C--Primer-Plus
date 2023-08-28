/*
@Author: mrxhar
@Date:   2023-08-26 20:30:27
@Email:  1337904145@qq.com
@Blog:
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

inline void eatline()
{
    while (std::cin.get() != '\n')
        continue;
}

struct planet
{
    char name[20];
    double population;
    double g;
};

const char *file = "planets.dat";

int main()
{
    using namespace std;
    planet p1;
    cout << fixed << right; // 格式化

    ifstream fin;

    // 预览
    fin.open(file, ios_base::in | ios_base::binary);
    if (fin.is_open())
    {
        cout << "Here are the current contents of the " << file << " file:\n";
        while (fin.read((char *)&p1, sizeof p1))
        {
            cout << setw(20) << p1.name << ": "
                 << setprecision(0) << setw(12) << p1.population
                 << setprecision(2) << setw(6) << p1.g << "\n";
        }
        fin.close();
    }

    // 写入
    ofstream fout (file, ios_base::out | ios_base::binary | ios_base::app);
    if (!fout.is_open()){
        cerr << "Can't open " << file << " file for output:\n";
        exit(EXIT_FAILURE);
    }

    cout << "Enter planet name (enter a blank line to quit): \n";
    cin.getline(p1.name, 20);
    while (p1.name[0] != '\0')
    {
        eatline();
        cout << "Enter planet population: ";
        cin >> p1.population;
        cout << "Enter planet's acceleration of gravity: ";
        cin >> p1.g;
        eatline();
        fout.write((char *)&p1, sizeof p1);
        cout << "Enter planet name (enter a blank line to quit): ";
        cin.getline(p1.name, 20);
    }
    fout.close();

    fin.clear();
    fin.open(file, ios_base::in | ios_base::binary);
    if (fin.is_open())
    {
        cout << "Here are the current contents of the " << file << " file:\n";
        while (fin.read((char *)&p1, sizeof p1))
        {
            cout << setw(20) << p1.name << ": "
                 << setprecision(0) << setw(12) << p1.population
                 << setprecision(2) << setw(6) << p1.g << "\n";
        }
        fin.close();
    }

    cout << "Done.\n";
    return 0;
}
