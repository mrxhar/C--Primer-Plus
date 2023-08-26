/*
@Author: mrxhar
@Date:   2023-08-26 10:42:51
@Email:  1337904145@qq.com
@Blog:   
*/


#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using std::cout;
using std::string;
using std::vector;
using std::list;

const int NUM = 10000000;

int main(){
    cout << "-----Begin-------\n";
    srand(time(0));
    vector<int> vio(NUM);

    for (int i = 0; i < NUM; i++)
    {
        vio[i] = rand();
    }

    vector<int> vi(vio);

    list<int> l1(vio.begin(), vio.end());

    cout << "Measure the sort() algorithm's running time for vector<int>\n";
    clock_t vector_start = clock();
    sort(vi.begin(), vi.end());
    clock_t vector_end = clock();
    cout << "The time is " << (double)(vector_end - vector_start) / CLOCKS_PER_SEC << "s.\n";

    cout << "Measure the sort() algorithm's running time for list<int>\n";
    clock_t list_start = clock();
    l1.sort();
    clock_t list_end = clock();
    cout << "The time is " << (double)(list_end - list_start) / CLOCKS_PER_SEC << "s.\n";

    cout << "Then measure the copy() and sort() algorithm's running time:\n";
    copy(vio.begin(), vio.end(), l1.begin());
    clock_t copy_start = clock();
    copy(l1.begin(), l1.end(), vi.begin());
    sort(vi.begin(), vi.end());
    copy(vi.begin(), vi.end(), l1.begin());
    clock_t copy_end = clock();
    cout << "The time is " << (double)(copy_end - copy_start) / CLOCKS_PER_SEC << "s.\n";

    return 0;
}
