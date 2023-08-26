/*
@Author: mrxhar
@Date:   2023-08-26 10:19:27
@Email:  1337904145@qq.com
@Blog:   
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(){
    using std::cout;
    using std::endl;
    using std::string;
    using std::vector;
    vector<string> mat_f, pat_f, total_f;

    cout << "Please enter Mat's frient (empty line to quit):" << endl;
    string temp;
    while (getline(std::cin, temp))
    {
        mat_f.push_back(temp);
        total_f.push_back(temp);
        if (temp == "\0")
        {
            break;
        }
    }

    cout << "The following are Mat's frient:\n";
    for (auto it = mat_f.begin(); it != mat_f.end(); it++)
    {
        cout << *it << "\n";
    }
    cout << endl;
    cout << "Please enter Pat's frient (empty line to quit):" << endl;
    while (getline(std::cin, temp))
    {
        pat_f.push_back(temp);
        total_f.push_back(temp);
        if (temp == "\0")
        {
            break;
        }
    }
    cout << "The following are Pat's frient:\n";
    for (auto it = pat_f.begin(); it != pat_f.end(); it++)
    {
        cout << *it << "\n";
    }

    cout << endl;

    sort(total_f.begin(), total_f.end());
    unique(total_f.begin(), total_f.end());
    cout << "There are " << total_f.size() << " friends\n";
    for (auto it = total_f.begin(); it != total_f.end(); it++)
    {
        cout << *it << "\n";
    }

    cout << endl;

    return 0;
}
