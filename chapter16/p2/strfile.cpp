/*
@Author: mrxhar
@Date:   2023-08-25 10:26:01
@Email:  1337904145@qq.com
@Blog:   
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main(){
    using namespace std;
    ifstream fin;
    fin.open("tobuy.txt");
    if (fin.is_open() == false) 
    {
        // 没有打开
        cerr << "Can't open file. Bye.\n";
        exit(EXIT_FAILURE);
    }
    string item;
    int count = 0;
    getline(fin, item, ':');
    while (fin)
    {
        ++count;
        cout << count << ": " << item << endl;
        getline(fin, item, ':');
    }
    cout << "Done!\n";
    fin.close();

    return 0;
}
