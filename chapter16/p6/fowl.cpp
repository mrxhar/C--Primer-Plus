/*
@Author: mrxhar
@Date:   2023-08-25 14:25:55
@Email:  1337904145@qq.com
@Blog:   
*/

#include <iostream>
#include <string>
#include <memory>

int main(){

    using namespace std;

    shared_ptr<string> films[5] =
        {
            shared_ptr<string>(new string("Fowl Balls")),
            shared_ptr<string>(new string("Duck walks")),
            shared_ptr<string>(new string("Chicken Runs")),
            shared_ptr<string>(new string("Trukey Errors")),
            shared_ptr<string>(new string("Goose Eggs")),
        };
    shared_ptr<string> pwin;
    pwin = films[2]; // 转让了所有权

    cout << "The mominees for best avian baseball film are\n";
    for (int i = 0; i < 5; i++)
    {
        cout << *films[i] << endl;
    }
    cout << "The winner is " << *pwin << "!\n";
    cin.get();

    return 0;
}
