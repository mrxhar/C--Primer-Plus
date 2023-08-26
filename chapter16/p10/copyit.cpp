/*
@Author: mrxhar
@Date:   2023-08-25 16:51:43
@Email:  1337904145@qq.com
@Blog:   
*/

#include <iostream>
#include <iterator>
#include <vector>


int main(){
    using namespace std;

    int casts[10] = {6, 7, 2, 9, 4, 11, 8, 7, 10, 5};
    vector<int> dice(10);

    // begin 正向迭代器
    copy(casts, casts + 10, dice.begin());
    cout << "Let the dice be cast!\n";


    ostream_iterator<int, char> out_iter(cout, " "); // cout 输出
    copy(dice.begin(), dice.end(), out_iter); // 使用cout进行显示
    cout << endl;

    cout << "Implicit the of reverse iterator.\n";
    copy(dice.rbegin(), dice.rend(), out_iter);
    cout << endl;

    cout << "Explicit use of reverse iterator.\n";
    vector<int>::reverse_iterator ri; //反向迭代器
    for (ri = dice.rbegin(); ri != dice.rend(); ++ri) // 递加就是递减
    {
        cout << *ri << " ";
    }

    cout << endl;
    return 0;
}
