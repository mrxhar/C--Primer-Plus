/*
@Author: mrxhar
@Date:   2023-08-26 21:12:38
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>
#include <sstream> // sstream 族支持
#include <string>  // string 类

int main()
{
    using namespace std;
    ostringstream outstr;
    string hdisk;
    cout << "What's the name of your hard disk? ";
    getline(cin, hdisk);

    int cap;
    cout << "What's its capacity in GB? ";
    cin >> cap;
    outstr << "The hard disk " << hdisk << " has a capacity of " << cap << " gigabytes."; 
    string result = outstr.str();
    cout << result << endl;

    return 0;
}
