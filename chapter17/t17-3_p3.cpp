/*
@Author: mrxhar
@Date:   2023-08-28 08:19:04
@Email:  1337904145@qq.com
@Blog:   
*/
#include <iostream>
#include <fstream>


int main()
{
    using namespace std;
    ifstream fin;
    ofstream fout;
    char ch;
    // fin.open(argv[1]);
    // fout.open(argv[2]);
    fin.open("input.txt");
    fout.open("output.txt");
    if (!fin.is_open())
    {
        cerr << "Error opening fin file" << endl;
        fin.clear();
        exit(EXIT_FAILURE);
    }

    if (!fout.is_open())
    {
        cerr << "Error opening fout file" <<  endl;
        fout.clear();
        exit(EXIT_FAILURE);
    }

    cout << "Open file sucessfully" << endl;
    while (fin.get(ch))
    {
        cout << ch;
        fout << ch;
    }

    fin.clear();
    fout.close();
    fin.close();

    return 0;
}


