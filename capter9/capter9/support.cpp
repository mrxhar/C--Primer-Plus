#include "support.h"
#include <iostream>

using namespace std;

void update(double dt) {
	warming += dt;
	cout << "Updating global warming to " << warming << " degrees.\n";
}

void local(void) {
	double warming = 0.8; // �ڲ��ɼ�
	cout << "Local warming = " << warming << " degrees.\n";
	cout << "But global warming = " << ::warming << " degrees.\n"; // :: �����������������ɷ���ȫ�ֱ���

}