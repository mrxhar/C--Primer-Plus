#ifndef MYTIME3_H_
#define MYTIME3_H_

#include <iostream>

const int H_to_M = 60;

class Time
{
public:
	Time();
	Time(int h, int m = 0);
	void Addmin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	Time operator+(const Time& t) const;
	Time operator-(const Time& t) const;
	Time operator*(double n) const;
	friend Time operator*(double m, const Time& t) {
		return t * m;
	}
	friend std::ostream& operator << (std::ostream& os,const Time& time);

private:
	int hours;
	int minutes;
};


#endif // !MYTIME3_H_

