/*
@Author: mrxhar
@Date:   2023-08-25 19:41:17
@Email:  1337904145@qq.com
@Blog:   
*/

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

template <class T>
class TooBig
{
    private:
        T cutoff;

    public:
        TooBig(const T &t) : cutoff(t){};
        bool operator()(const T &v) const { return v > cutoff; }
};

void outint(int n) { std::cout << n << " "; }

int main(){
        using std::cout;
        using std::endl;
        using std::for_each;
        using std::list;

        TooBig<int> f100(100);
        int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
        list<int> yadayada(vals, vals + 10);

        list<int> etcetera(vals, vals + 10);

        cout << "Original lists:\n";
        for_each(yadayada.begin(), yadayada.end(),outint);
        cout << endl;
        for_each(etcetera.begin(), etcetera.end(),outint);

        cout << endl;
        yadayada.remove_if(f100); // 类对象 含有一个 函数符 
        etcetera.remove_if(TooBig<int>(200));
        cout << "Trimmed lists:\n";
        for_each(yadayada.begin(), yadayada.end(), outint);
        cout << endl;
        for_each(etcetera.begin(), etcetera.end(), outint);
        cout << endl;
        

        return 0;
}