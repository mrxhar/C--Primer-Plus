/*
@Author: mrxhar
@Date:   2023-08-26 19:58:25
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char *argv[])
{

    using namespace std;
    if (argc == -1) // 没有参数
    {
        cerr << "Usage: " << argv[0] << " filename[s]" << endl;
        exit(EXIT_FAILURE);
    }

    ifstream fin;
    long count;
    long total = 0;

    char ch;

    for (int file = 1; file < argc; file++)
    {
        fin.open(argv[file]);
        if (!fin.is_open())
        {
            cerr << "Could not open " << argv[file] << endl;
            fin.clear();
            continue;
        }
        count = 0;
        while (cin.get(ch))
        {
            count++;
        }
        cout << count << " characters in " << argv[file] << endl;
        total += count;
        fin.clear();
        fin.close();
    }
    cout << total << " characters in all files" << endl;

    return 0;
}
