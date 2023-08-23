/*
@Author: mrxhar
@Date:   2023-08-22 21:18:49
@Email:  1337904145@qq.com
@Blog:
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

template <typename T>
class ManyFriend
{
private:
    T item;

public:
    ManyFriend(const T &i) : item(i) {}

    template <typename C, typename D>
    friend void show2(C &, D &);
};

template <typename C, typename D>
void show2(C & c, D & d)
{
    cout << c.item << ", " << d.item << endl;
}

int main()
{
    ManyFriend<int> hfi1(10);
    ManyFriend<int> hfi2(20);
    ManyFriend<double> hfdb(10.5);

    cout << "hfi1, hfi2: ";
    show2(hfi1, hfi2);

    cout << "hfdb, hfi1: ";
    show2(hfdb, hfi1);
    return 0;
}
