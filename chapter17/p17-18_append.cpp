/*
@Author: mrxhar
@Date:   2023-08-26 20:10:17
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

const char *file = "guests.txt";
int main()
{
    using namespace std;

    char ch;
    ifstream fin;
    fin.open(file);

    // 预览文件
    if (fin.is_open())
    {
        cout << "Here are the current contents of the "
             << file << " file:\n";
        while (fin.get(ch))
        {
            cout << ch;
        }
        fin.close(); // 关闭
    }

    ofstream fout(file, ios::out | ios::app); // 追加写入
    if (!fout.is_open())
    {
        cerr << "Can't open " << file << " file for output.\n";
        exit(EXIT_FAILURE);
    }

    cout << "Enter guest names (enter a blank line to quit):\n";
    string name;

    while (getline(cin, name) && name.size() > 0)
    {
        fout << name << endl;
    }
    fout.close();

    // 重新打开预览
    fin.clear();
    fin.open(file);

    if (fin.is_open()) // 预览文件
    {
        cout << "Here are the new contents of the "
             << file << " file:\n";
        while (fin.get(ch))
        {
            cout << ch;
        }
        fin.close();
    }

    cout << "Done.\n";
    return 0;
}
