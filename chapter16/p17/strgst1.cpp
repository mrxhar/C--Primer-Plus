/*
@Author: mrxhar
@Date:   2023-08-25 20:15:06
@Email:  1337904145@qq.com
@Blog:   
*/

#include <iostream>
#include <string>
#include <algorithm>


int main(){
    using namespace std;

    string letters;

    cout << "Enter the letters grouping (quit to quit): ";
    while (cin >> letters && letters != "quit")
    {
        cout << "Permutations of " << letters << endl;
        sort(letters.begin(), letters.end());
        cout << letters << endl;
        while (next_permutation(letters.begin(), letters.end()))
        {
            cout << letters << endl;
        }
        cout << "Enter next sequence (quit to quit): ";
    }
    cout << "Done." << endl;
    
    return 0;
}
