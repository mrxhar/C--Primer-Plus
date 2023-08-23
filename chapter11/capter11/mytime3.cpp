#include "mytime3.h"

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

Time Time::operator-(const Time& t)const {
	Time diff;
	int tot1, tot2;
	tot1 = t.minutes + 60 * t.hours;
	tot2 = minutes + 60 * hours;
	diff.minutes = (tot2 - tot1) % H_to_M;
	diff.hours = (tot2 - tot1) / H_to_M;
	return diff;
}

Time Time::operator*(double mult) const {
	Time result;
	long totalminutes = hours * mult * 60 + minutes * mult;
	result.minutes = totalminutes % H_to_M;
	result.hours = totalminutes / H_to_M;
	return result;
}

std::ostream & operator<<(std::ostream & os,const Time & t) {
	os << t.hours << " hours, " << t.minutes << " minutes";
	return os;
}
