#include <iostream>
#include "strngbad.h"

using std::cout;

void callme1(StringBad&); // refrence
void callme2(StringBad); // value

int main()
{
	using std::endl;
	// ʹ�� ����� ����ʾ��������
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
		callme2(headline2); // ֵ���ݻᴴ��һ������������һ�θ��ƹ��캯��
		cout << "headline2: " << headline2 << endl; 

		cout << "Initialize one object to another:\n";
		StringBad sailor = sports; // ���ƹ��캯����û��num_string ++ �Ĳ���
		cout << "sailor: " << sailor << endl; // ��ֵ�����ᴴ��һ����ʱ���������ʱ�����ɸ�ֵǳ���ƹ��캯������,��ֵ���캯����ֵ���ݣ����Ƶ���ָ�룬��û����������һ����ַ����ֵ�洢��
		cout << "Assign one object to another:\n";
		StringBad knot;
		knot = headline1; // knot �� headline1 ָ��ͬһ��ָ���ַ������knot�ͷź� headline1�����𣬳���
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
	// �������⣬�����һ�� StringBad ���ͷ�
	cout << "String passed by value:\n";
	cout << "   \"" << sb << "\"\n";
}