#include "support.h"
#include <iostream>

using namespace std;

void update(double dt) {
	warming += dt;
	cout << "Updating global warming to " << warming << " degrees.\n";
}

void local(void) {
	double warming = 0.8; // 内部可见
	cout << "Local warming = " << warming << " degrees.\n";
	cout << "But global warming = " << ::warming << " degrees.\n"; // :: 作用域解析运算符，可访问全局变量

}