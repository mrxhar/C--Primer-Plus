/*
@Author: mrxhar
@Date:   2023-08-22 20:46:31
@Email:  1337904145@qq.com
@Blog:   
*/
#include <iostream>
#include "stacktp.h"

template <template <typename T> class Thing>
class Crab // Thing 也是一个模板类
{
private:
    Thing<int> s1; // 模板类的具体化
    Thing<double> s2;

public:
    Crab(){};
    bool push(int a, double x) { return s1.push(a) && s2.push(x); };
    bool pop(int &a, double &x) { return s1.pop(a) && s2.pop(x); };
};


int main(){
    using std::cin;
    using std::cout;
    using std::endl;
    Crab<Stack> nebula;

    int ni;
    double nb;
    cout << "Enter int double pairs, such as 4 3.5 (0 0 to end):\n";
    while (cin >> ni >> nb && ni > 0 && nb > 0)
    {
        if (!nebula.push(ni,nb))
        {
            break;
        }
    }

    while (nebula.pop(ni,nb))
    {
        cout << ni << ", " << nb << endl;
    }
    cout << "Done!" << endl;

    return 0;
}
