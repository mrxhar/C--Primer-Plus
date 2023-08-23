#include "text5.h"


int main()
{
	using std::cout;
	using std::endl;
	Stonewt st1(120.192);
	Stonewt st2(10, 20.7312);
	cout << "st1(ST) = " << st1 << endl;
	cout << "st2(ST) = " << st2 << endl;

	st1.set_POUND();
	st2.set_POUND();
	cout << "st1(POUND) = " << st1 << endl;
	cout << "st2(POUND) = " << st2 << endl;


	st1.set_POUND_F();
	st2.set_POUND_F();
	cout << "st1(POUNDF) = " << st1 << endl;
	cout << "st2(POUNDF) = " << st2 << endl;
	
	cout << "st1 + st2 = " << st1 + st2 << endl;
	cout << "st1 - st2 = " << st1 - st2 << endl;
	cout << "0.1 * st2 = " << 0.1 *  st2 << endl;

}