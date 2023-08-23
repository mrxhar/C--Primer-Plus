#include <iostream>
#include "dma3.h"

int main()
{
    using std::cout;
    using std::endl;

    // baseDMA shirt("Portablly", 8);
    // lacksDMA balloon("red", "Blimpo", 5);
    // hasDMA map("Mercator", "Buffalo Keys", 5);

    DMAABC *p_dma[3] = {
        new baseDMA("Portablly", 8),
        new lacksDMA("red", "Blimpo", 5),
        new hasDMA("Mercator", "Buffalo Keys", 5)};

    cout << "Displaying baseDMA object:\n";
    p_dma[0]->View();

    cout << "Displaying lacksDMA object:\n";
    p_dma[1]->View();

    cout << "Displaying hasDMA object:\n";
    p_dma[2]->View();

    lacksDMA balloon2(*(lacksDMA *)p_dma[1]); // 先转换成派生类指针，再取值即可
    cout << "Result of lacksDMA copy:\n";
    balloon2.View();

    hasDMA map2;
    map2 = *(hasDMA *)p_dma[2]; // 赋值

    cout << "Result of hasDMA assignment:\n";
    map2.View();

    return 0;
}