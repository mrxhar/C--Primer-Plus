/*
@Author: mrxhar
@Date:   2023-08-25 11:11:06
@Email:  1337904145@qq.com
@Blog:
*/
#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string empty;
    string samll = "bit";
    string larger = "Elephant are a girl's best friend";
    cout << "Size: \n";
    cout << "\tempty: " << empty.size() << "\n"
         << "\tsamll: " << samll.size() << "\n"
         << "\tlarger: " << larger.size() << "\n"
         << "Capacities:\n";
    cout << "\tempty: " << empty.capacity() << "\n"
         << "\tsamll: " << samll.capacity() << "\n"
         << "\tlarger: " << larger.capacity() << "\n";
    empty.reserve(50);
    cout << "Capacity after empty.reserve(50): "
         << empty.capacity() << endl;
    return 0;
}
