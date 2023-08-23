#include <iostream>
#include "mytime1.h"

Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::AddHr(int h) {
	hours += h;
}

void Time::Addmin(int m) {
	minutes += m;
	hours += minutes / H_to_M;
	minutes %= H_to_M;
}

void Time::Reset(int h, int m) {
	hours = h;
	minutes = m;
}

Time Time::operator+(const Time& t) const {
	Time sum(hours, minutes);
	sum.AddHr(t.hours);
	sum.Addmin(t.minutes);
	return sum;
}

void Time::Show() const {
	std::cout << hours << " hours, " << minutes << " minutes\n";
}
