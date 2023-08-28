/*
@Author: mrxhar
@Date:   2023-08-26 17:10:10
@Email:  1337904145@qq.com
@Blog:   
*/

#include <iostream>

int main(){
    using namespace std;
    cout << "Enter numbers: ";

    int sum = 0;
    int input;
    while (cin >> input)
    {
        sum += input;
    }

    cout << "Last value entered = " << input << endl;
    cout << "Sum = " << sum << endl;
    
    return 0;
}
