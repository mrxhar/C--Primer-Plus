/*
@Author: mrxhar
@Date:   2023-08-28 08:48:41
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <iterator>
#include <algorithm>

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

    string temp;
    set<string> mat, pat, matnpat;

    while (getline(fin1, temp))
    {
        mat.insert(temp);
    }
    ostream_iterator<string, char> output(cout, "\n");
    cout << "mat: freads are: \n";
    copy(mat.begin(), mat.end(), output);
    while (getline(fin2, temp))
    {
        pat.insert(temp);
    }

    cout << "pat: freads are: \n";
    copy(pat.begin(), pat.end(), output);
    ostream_iterator<string,char> outfile(fout, "\n");
    set_union(mat.begin(), mat.end(), pat.begin(), pat.end(), insert_iterator<set<string>>(matnpat, matnpat.begin()));
    cout << "matnpat: freads are: \n";
    copy(matnpat.begin(), matnpat.end(), output);
    copy(matnpat.begin(), matnpat.end(), outfile);
    return 0;
}
