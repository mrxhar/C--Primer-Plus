/*
@Author: mrxhar
@Date:   2023-08-26 09:45:56
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>
#include <algorithm>

int reduce(long ar[], int n);

int main()
{
    long testarr[10] = {156, 124, 23, 43, 35, 23, 124, 199, 210, 156};
    std::cout << "The following is my original array:\n";
    for (int i = 0; i < 10; i++)
    {
        std::cout << testarr[i] << " ";
    }
    std::cout << std::endl;
    int newsize = reduce(testarr, 10);
    std::cout << "After reduction, the array:\n";
    for (int i = 0; i < newsize; i++)
    {
        std::cout << testarr[i] << " ";
    }
    std::cout << std::endl;
    system("pause");

    return 0;
}

int reduce(long ar[], int n)
{
    std::sort(ar, ar + n); // sort 函数
    long *new_ar;
    new_ar = std::unique(ar, ar + n);
    return new_ar - ar;
}

