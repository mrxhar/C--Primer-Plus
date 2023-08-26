/*
@Author: mrxhar
@Date:   2023-08-25 17:05:20
@Email:  1337904145@qq.com
@Blog:   
*/

#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>

void output(const std::string &s) { std::cout << s << " "; }

int main(){
    using namespace std;

    string s1[4] = {"fine", "fish", "fashion", "fate"};
    string s2[2] = {"busy", "bats"};
    string s3[2] = {"silly", "singers"};

    vector<string> words(4);

    copy(s1, s1 + 4, words.begin());
    for_each(words.begin(), words.end(), output);
    cout << endl;

    copy(s2, s2 + 2, back_insert_iterator<vector<string>>(words));// 函数 ,加到后面
    for_each(words.begin(), words.end(), output);
    cout << endl;

    copy(s3, s3 + 2, insert_iterator<vector<string>>(words, words.begin())); // 插入，以及插入的位置
    for_each(words.begin(), words.end(), output);
    cout << endl;

    return 0;
}
