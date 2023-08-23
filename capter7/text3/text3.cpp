// text3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

struct box {
    char maker[40];
    float height;
    float width;
    float length;
    float volumn;
};

void set_box(box* p_b);
void show(box b);
int main()
{
    box b = { "cube",3,4,5, };
    set_box(&b);
    show(b);
    return 0;
}

void set_box(box* p_b) {
    p_b->volumn = p_b->height * p_b->length * p_b->width;
}

void show(box b) {
    cout << "maker: " << b.maker << endl;
    cout << "height: " << b.height << endl;
    cout << "width: " << b.width << endl;
    cout << "length: " << b.length << endl;
    cout << "volumn: " << b.volumn << endl;

}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
