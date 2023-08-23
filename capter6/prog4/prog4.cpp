// prog4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
const int strsize = 80;
const int usersize = 4;

struct bop {
    char fullname[strsize];
    char title[strsize];
    char bopname[strsize];
    int preference;
};


bop user[usersize] = {
    {"Rick","Lever_A","RR",0},
    {"Jack","Lever_B","JJ",1},
    {"Micheal","Level_C","MM",2},
    {"Rose","Level_D","RR",0}
};

void showmenu();
void print_by_fullname(void);
void print_by_title(void);
void print_by_bopname(void);
void print_by_pref(void);

int main()
{
    char input;
    showmenu();
    cin.get(input);
    while (input != 'q')
    {
        switch (input)
        {
        case 'a': print_by_fullname(); break;
        case 'b': print_by_title(); break;
        case 'c': print_by_bopname(); break;
        case 'd': print_by_pref(); break;

        default:
            cout << "Please enter character a, b, c, d, q:" << endl;
        }
        cin.get();
        cin.get(input);
    }
    return 0;
}

void showmenu() {
    cout << "Benevolent Order of Programmer Report" << endl;
    cout << "a. display by name\t\t b. display by title" << endl;
    cout << "c. display by bopname\t\t d. display by perference" << endl;
    cout << "q. quit" << endl;
}
void print_by_fullname(void) {
    for (int i = 0; i < usersize; i++)
    {
        cout << user[i].fullname << endl;
    }
}
void print_by_title(void) {
    for (int i = 0; i < usersize; i++)
    {
        cout << user[i].title << endl;
    }
}
void print_by_bopname(void) {
    for (int i = 0; i < usersize; i++)
    {
        cout << user[i].bopname << endl;
    }
}
void print_by_pref(void) {
    for (int i = 0; i < usersize; i++)
    {
        switch (user[i].preference)
        {
        case 0:cout << user[i].fullname << endl; break;
        case 1:cout << user[i].title << endl; break;
        case 2:cout << user[i].bopname << endl; break;
        default:
            break;
        }
    }
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
