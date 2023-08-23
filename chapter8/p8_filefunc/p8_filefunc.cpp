// p8_filefunc.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int LIMIT= 5;

void file_it(ostream& os, double fo, const double fe[], int n);
int main()
{
    fstream fout;
    const char* fn = "ep-data.txt";

    fout.open(fn);
    if (!(fout.is_open()))
    {
        cout << "Can't open" << fn << ". Bye." << endl;
        exit(EXIT_FAILURE);
    }
    double objective;
    cout << "Enter the focal length of your telescope objective in mm: ";
    cin >> objective;

    double eps[LIMIT];
    for (int i = 0; i < LIMIT; i++)
    {
        cout << "EyePieces #" << i + 1 << ":";
        cin >> eps[i];
    }

    file_it(cout, objective, eps, LIMIT);
    file_it(fout, objective, eps, LIMIT);
    cout << "Done." << endl;
    return 0;
}

void file_it(ostream& os, double fo, const double fe[], int n) {
    os << "Focal length of objective; " << fo << endl;
    os << "f.1. eyepieces" << " magnification" << endl;
    for (int i = 0; i < n; i++)
    {
        os << "   "  << fe[i] << "   " << int(fo / fe[i] + 0.5) << endl;
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
