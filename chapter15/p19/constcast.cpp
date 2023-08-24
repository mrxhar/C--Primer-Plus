/*
@Author: mrxhar
@Date:   2023-08-24 19:58:13
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>
using std::cout;
using std::endl;

void change(const int *pt, int n);

int main()
{
    int pop1 = 38383;
    const int pop2 = 2000; // 没有改变 因为本身 pop2 是 const，pt 是一个指向const的const指针

    cout << "pop1, pop2: " << pop1 << ", " << pop2 << endl;
    change(&pop1, -103);
    change(&pop2, -103);
    cout << "pop1, pop2: " << pop1 << ", " << pop2 << endl;
    return 0;
}

void change(const int *pt, int n)
{
    int *pc;
    pc = const_cast<int *>(pt);
    *pc += n;
}