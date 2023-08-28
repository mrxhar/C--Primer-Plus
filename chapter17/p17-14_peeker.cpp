/*
@Author: mrxhar
@Date:   2023-08-26 19:26:59
@Email:  1337904145@qq.com
@Blog:   
*/
#include <iostream>

// main函数
int main(){
    using std::cout;
    using std::cin;
    using std::endl;

    // 定义一个字符变量ch
    char ch;

    // 循环读取输入流中的字符
    while (cin.get(ch))
    {
        // 如果不是'#'，则输出字符
        if (ch!= '#')
        {
            cout << ch;
        }
        // 如果是'#'，则将字符放回输入流
        else
        {
            cin.putback(ch); 
            break;
        }
    }


    // 如果输入流未到文件尾，则继续读取
    if (!cin.eof()) // 没到文件尾
    {
        cin.get(ch);
        cout << endl
             << ch << " is next input character.\n";
    }
    else{
        cout << "End of file reached.\n";
        std::exit(0);
    }

    // 当输入流未到文件尾时，从输入流中读取一个字符
    while (cin.peek()!= '#')
    {
        cin.get(ch);
        cout << ch;
    }

    // 当输入流未到文件尾时，从输入流中读取一个字符
    if (!cin.eof())
    {
        cin.get(ch);
        cout << endl << ch << " is next input character.\n";
    }
    else
    {
        cout << "End of file reached.\n";
    }
    
    // 返回0
    return 0;
}