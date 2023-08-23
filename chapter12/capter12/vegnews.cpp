#include <iostream>
#include "strngbad.h"

using std::cout;

void callme1(StringBad&); // refrence
void callme2(StringBad); // value

int main()
{
	using std::endl;
	// 使用 代码块 以显示析构函数
	{
		cout << "Starting an inner block.\n";
		StringBad headline1("Celery Stalks at Midnight");
		StringBad headline2("Lettuce Prey");
		StringBad sports("Spinach Leaves Bowl for Dollars");

		cout << "headline1: " << headline1 << endl;
		cout << "headline2: " << headline2 << endl;
		cout << "sports: " << sports << endl;

		callme1(headline1);
		cout << "headline1: " << headline1 << endl;
		callme2(headline2); // 值传递会创建一个副本，调用一次复制构造函数
		cout << "headline2: " << headline2 << endl; 

		cout << "Initialize one object to another:\n";
		StringBad sailor = sports; // 复制构造函数，没有num_string ++ 的操作
		cout << "sailor: " << sailor << endl; // 赋值操作会创建一个临时对象，这个临时对象由赋值浅复制构造函数生成,赋值构造函数按值传递，复制的是指针，并没有重新生成一个地址进行值存储。
		cout << "Assign one object to another:\n";
		StringBad knot;
		knot = headline1; // knot 与 headline1 指向同一个指针地址，所以knot释放后 headline1会受损，出错。
		cout << "knot: " << knot << endl;
		cout << "Exiting the block.\n";
	}
	cout << "End of main()\n";
}

void callme1(StringBad& rsb)
{
	cout << "String passed by reference:\n";
	cout << "   \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
	// 产生问题，会造成一个 StringBad 的释放
	cout << "String passed by value:\n";
	cout << "   \"" << sb << "\"\n";
}