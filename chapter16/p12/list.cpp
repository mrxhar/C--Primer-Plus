/*
@Author: mrxhar
@Date:   2023-08-25 18:47:31
@Email:  1337904145@qq.com
@Blog:   
*/

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

void outint(int n) { std::cout << n << " "; }

int main(){
    using namespace std;

    list<int> one(5, 2); // 5 个 2
    int stuff[5] = {1, 2, 4, 8, 6};
    list<int> two;
    two.insert(two.begin(), stuff, stuff + 5);
    int more[6] = {6, 4, 2, 4, 6, 5};
    list<int> three(two);
    three.insert(three.end(), more, more + 6);

    cout << "List one: ";
    for_each(one.begin(), one.end(), outint);
    cout << "\nList two: ";
    for_each(two.begin(), two.end(), outint);
    cout << "\nList three: ";
    for_each(three.begin(), three.end(), outint);

    three.remove(2); // 移除所有为 2 的值
    cout << "\nList  three minus 2s: ";
    for_each(three.begin(), three.end(), outint);

    three.splice(three.begin(), one); // 插入到 begin() 前面
    cout << "\nList three after splice: "; 
    for_each(three.begin(), three.end(), outint);

    cout << "\nList one:";
    for_each(one.begin(), one.end(), outint); // 会清空 one 里面的值

    three.unique();
    cout << "\nList three after unique: ";
    for_each(three.begin(), three.end(), outint);

    three.sort();
    three.unique();
    cout << "\nList three after sort & unique: ";
    for_each(three.begin(), three.end(), outint);

    two.sort();
    three.merge(two);
    cout << "\nSorted two merged into three: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl;
    return 0;
}
