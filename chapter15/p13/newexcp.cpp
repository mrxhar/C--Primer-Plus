/*
@Author: mrxhar
@Date:   2023-08-24 15:45:59
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>
#include <new>
#include "cstdlib"

using namespace std;

struct Big
{
    double stuff[20000]; // 8 * 20000
};

int main()
{
    Big *pb;
    try
    {
        cout << "Trying to get a big block of memory:\n";
        pb = new(std::nothrow) Big[1000000]; // 异常则 返回一个空指针
        if (pb == nullptr)
        {
            cout << "Couldn't allocate memory. Bye!" << endl;
            exit(EXIT_FAILURE);
        }
        

        // Big * pq = new Big[700000]; // 10000 * 8 * 800000 = 160000000000
        cout << "Got past the new request:\n";
    }
    catch (bad_alloc &ba)   
    {
        cout << "Caught the exception!\n";
        cout << ba.what() << "\n";
        exit(EXIT_FAILURE);
    }

    cout << "Memory successfully allocated:\n";
    pb[0].stuff[0] = 4;
    cout << pb[0].stuff[0] << endl;
    delete[] pb;

    return 0;
}
