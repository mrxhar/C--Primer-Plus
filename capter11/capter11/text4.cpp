#include "text4.h"

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

Time operator+(const Time& t1,const Time& t2){
	int tot = t1.hours * 60 + t1.minutes;
	tot += t2.hours * 60 + t2.minutes;
	return Time(tot / H_to_M, tot % H_to_M);
}

Time operator-(const Time& t1, const Time& t2) {
	int tot = t1.hours * 60 + t1.minutes;
	tot -= t2.hours * 60 + t2.minutes;
	return Time(tot / H_to_M, tot % H_to_M);
}

Time operator*(const Time& t, double n) {
	int tot = t.hours * n *  60 + t.minutes * n;
	return Time(tot / H_to_M, tot % H_to_M);
}

Time operator*(double n,const Time& t) {
	int tot = t.hours * n * 60 + t.minutes * n;
	return Time(tot / H_to_M, tot % H_to_M);
}

std::ostream & operator<<(std::ostream & os,const Time & t) {
	os << t.hours << " hours, " << t.minutes << " minutes";
	return os;
}
