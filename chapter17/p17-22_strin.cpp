/*
@Author: mrxhar
@Date:   2023-08-26 21:19:01
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>
#include <sstream>
#include <string>

int main()
{
    using namespace std;

    string lit = "It was a dark and stormy day, and the full moon glowed brilliantly. ";
    istringstream instr(lit); // 构造一个输入流对象
    string word;
    while (instr >> word) // 读取流中的单词
    {
        cout << word << endl;
    }

    return 0;
}
