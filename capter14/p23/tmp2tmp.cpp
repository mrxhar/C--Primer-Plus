/*
@Author: mrxhar
@Date:   2023-08-22 20:53:22
@Email:  1337904145@qq.com
@Blog:
*/
#include <iostream>
using std::cout;
using std::endl;

// template prototypes
template <typename T>
void counts();
template <typename T>
void report(T &);

// template class

template <typename TT>
class HasFriendT
{
private:
    TT item;
    static int ct;

public:
    HasFriendT(const TT &i) : item(i) { ct++; };
    ~HasFriendT() { ct--; };
    friend void counts<TT>();
    friend void report<>(HasFriendT<TT> &);
};

template <typename TT>
int HasFriendT<TT>::ct = 0;


// template friend functions definitions
template <typename T>
void counts()
{
    cout << "template size: " << sizeof(HasFriendT<T>) << "; ";
    cout << "template counts(): " << HasFriendT<T>::ct << "\n";
}
template <typename T>
void report(T &hf) // 使用 T 这是与 声明一致
{
    cout << hf.item << endl;
}

int main()
{
    counts<int>();
    
    HasFriendT<int> hfi1(10);
    HasFriendT<int> hfi2(20);
    HasFriendT<double> hfdb(10.5);

    report(hfi1);
    report(hfi2);
    report(hfdb);

    cout << "counts<int>() output:\n";
    counts<int>();

    cout << "counts<double>() output:\n";
    counts<double>();
    return 0;
}
