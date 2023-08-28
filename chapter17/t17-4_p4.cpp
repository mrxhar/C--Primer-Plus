/*
@Author: mrxhar
@Date:   2023-08-28 08:27:13
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    using namespace std;
    ifstream fin1, fin2;
    ofstream fout;
    fin1.open("input1.txt");
    if (!fin1.is_open())
    {
        cerr << "Error opening fin file" << endl;
        fin1.clear();
        exit(EXIT_FAILURE);
    }

    fin2.open("input2.txt");
    if (!fin2.is_open())
    {
        cerr << "Error opening fin file" << endl;
        fin2.clear();
        exit(EXIT_FAILURE);
    }

    fout.open("output.txt");
    if (!fout.is_open())
    {
        cerr << "Error opening fin file" << endl;
        fout.clear();
        exit(EXIT_FAILURE);
    }

    cout << "Open file sucessfully!" << endl;
    string input1, input2, output;
    int count1, count2;
    count1 = count2 = 0;
    while (getline(fin1, input1))
    {
        count1++;
    }
    while (getline(fin2, input2))
    {
        count2++;
    }

    int count3 = count1 <= count2 ? count1 : count2;

    fin1.clear();
    fin2.clear();
    fin1.close();
    fin2.close();
    fin1.open("input1.txt");
    if (!fin1.is_open())
    {
        cerr << "Error opening fin file" << endl;
        fin1.clear();
        exit(EXIT_FAILURE);
    }
    fin2.open("input2.txt");
    if (!fin2.is_open())
    {
        cerr << "Error opening fin file" << endl;
        fin2.clear();
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < count3; i++)
    {
        getline(fin1, input1);
        getline(fin2, input2);
        output = input1 + " " + input2;
        fout << output << endl;
    }
    if (count1 <= count2)
    {
        for (int i = count3; i < count2; i++)
        {
            getline(fin2, input2);
            output = input2;
            fout << output << endl;
        }
    }
    else
    {
        for (int i = count3; i < count1; i++)
        {
            getline(fin1, input1);
            output = input1;
            fout << output << endl;
        }
    }

    cout << "Write file sucessfully!" << endl;

    return 0;
}
