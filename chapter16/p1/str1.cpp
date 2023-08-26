/*
@Author: mrxhar
@Date:   2023-08-25 10:10:59
@Email:  1337904145@qq.com
@Blog:   
*/

#include <iostream>
#include <string>


int main(){

    using std::cout;
    using std::endl;
    using std::string;

    string one("Lottery Winner!");
    cout << one << endl;

    string two(20, '$'); // 包含 20 个 $ 字符串
    cout << two << endl;

    string three(one);
    cout << three << endl; // 复制构造函数

    one += " Oops!"; // += 
    cout << one << endl;

    two = "Sorry, That was ";
    three[0] = 'P';
    string four; // 默认
    four = two + three; // + ， =
    cout << four << endl;

    char alls[] = "All's well that ends well";
    string five(alls, 20);
    cout << five << endl;

    string six(alls + 6, alls + 10);// 区间
    cout << six << endl;

    string seven(&five[6], &five[10]);
    cout << seven << endl;

    string eight(four, 7, 16);
    cout << eight << endl;

    return 0;
}