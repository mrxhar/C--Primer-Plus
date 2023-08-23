// prog6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include<fstream>
#include<cstdlib>
#include <string>
using namespace std;

struct patrons {
    string name;
    double donation;
};

int main()
{

    ifstream inFile;
    string file_name;

    int number;
    patrons* ppatrons; // 动态分配
    bool empty = true;

    cout << "Enter the file name: ";
    getline(cin, file_name);
    inFile.open(file_name);
    if (!inFile.is_open())
    {
        cout << "Failed to open the file!\n";
        exit(EXIT_FAILURE);
    }
    inFile >> number;
    if (number <= 0)
    {
        exit(EXIT_FAILURE);
    }
    ppatrons = new patrons[number];
    
    inFile.get();
    int i = 0;
    while (!inFile.eof() && (i < number))
    {
        getline(inFile, ppatrons[i].name);
        cout << "Read name: " << ppatrons[i].name << endl;
        inFile >> ppatrons[i].donation;
        cout << "Read name: " << ppatrons[i].donation << endl;
        i++;
        inFile.get();
    }

    cout << "******* Grand Patrons *********\n";
    for (int i = 0; i < number; i++)
    {
        if (ppatrons[i].donation >= 10000)
        {
            cout << ppatrons[i].name << ": " << ppatrons[i].donation << endl;
            empty = false;
        }
    }
    if (empty == true)
    {
        cout << "None" << endl;
    }

    cout << "******* Patrons *********\n";
    empty = true;
    for (int i = 0; i < number; i++)
    {
        if (ppatrons[i].donation <= 10000)
        {
            cout << ppatrons[i].name << ": " << ppatrons[i].donation << endl;
            empty = false;
        }
    }
    if (empty == true)
    {
        cout << "None" << endl;
    }
    inFile.close();

    return 0;
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
