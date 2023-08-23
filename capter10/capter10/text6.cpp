#include "text6.h"


Move::Move(double a, double b) {
	x = a;
	y = b;
}

void Move::showmove() const
{
	cout << "x = " << x << ", y = " << y << endl;
}

Move Move::add(const Move& m)
{
	Move temp;

	temp.x = m.x + x;
	temp.y = m.y + y;

	return temp;
}

void Move::reset(double a, double b) {
	x = a;
	y = b;
}