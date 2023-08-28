/*
@Author: mrxhar
@Date:   2023-08-26 17:19:34
@Email:  1337904145@qq.com
@Blog:   
*/
#include <iostream>
#include <exception>


int main(){
    using namespace std;
    cin.exceptions(ios_base::failbit); 

    cout << "Enter a number: ";
    int sum = 0;
    int input;
    try
    {
        while (cin >> input)
        {
            sum += input;
        }
        
    }
    catch(ios_base::failure& bf)    
    {
        cout << bf.what() << endl;
        cout << "O! the horror!\n";
    }

    cout << "Last value entered = " << input << endl;
    cout << "Sum = " << sum << endl;

    return 0;
}
