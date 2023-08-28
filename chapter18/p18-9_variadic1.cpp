/*
@Author: mrxhar
@Date:   2023-08-28 14:59:19
@Email:  1337904145@qq.com
@Blog:   
*/

#include <iostream>
#include <string>

void show_list3(){}

template <typename T,typename... Args>
void show_list3(T value,Args... args){
    std::cout << value << ", ";
    show_list3(args...);
}

int main(){
    int n = 4;
    double x = 2.71828;
    std::string mr = "Mr. String objects!";
    show_list3(n, x);
    show_list3(x * x, '!', 7, mr);

    return 0;
}


