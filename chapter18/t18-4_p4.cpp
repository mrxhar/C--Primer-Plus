/*
@Author: mrxhar
@Date:   2023-08-28 17:21:07
@Email:  1337904145@qq.com
@Blog:
*/

#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>

auto out_lambda = [](int n)
{ std::cout << n << " "; };

int main()
{
    int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    std::list<int> yadayada(vals, vals + 10);
    std::list<int> etcetera(vals, vals + 10);

    std::cout << "Original data\n";
    std::for_each(yadayada.begin(), yadayada.end(), out_lambda);
    std::cout << "\n";
    std::for_each(etcetera.begin(), etcetera.end(), out_lambda);
    std::cout << std::endl;

    yadayada.remove_if([](int n)
                       { return n > 100; });
    etcetera.remove_if([](int n)
                       { return n > 200; });
    std::cout << "Termmed data\n";
    std::for_each(yadayada.begin(), yadayada.end(), out_lambda);
    std::cout << "\n";
    std::for_each(etcetera.begin(), etcetera.end(), out_lambda);
    std::cout << std::endl;

    return 0;
}
