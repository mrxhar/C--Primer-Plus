// sumafile.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
const int SIZE = 60;
int main()
{
    char filenames[SIZE];

    ifstream inFile;
    cout << "Enter name of data file: ";
    cin.getline(filenames, SIZE);

    inFile.open(filenames);
    if (!inFile.is_open()) // 判断是是否打开
    {
        cout << "Cloud not open the file " << filenames << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE); // 出错 exit （习惯）相当于 return
    }
    cout << "Suceess open the txt file." << endl;

    double value;
    double sum = 0.0;
    int count = 0;

    inFile >> value;
    while (inFile.good()) // 读取成功,文件中读取的数据是否成功
    {
        ++count;
        sum += value;
        inFile >> value;
    }

    if (inFile.eof()) // 文件末尾
    {
        cout << "End of file reached.\n";
    }
    else if (inFile.fail())
    {
        cout << "Input terminated by data mismatch.\n";
    }
    else
    {
        cout << "Input terminated for unkown reason.\n";
    }
    if (count == 0) {
        cout << "No data processed.\n";
    }
    else
    {
        cout << "Item read: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << sum / count << endl;
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
