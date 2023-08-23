#ifndef TEXT4_H_
#define TEXT4_H_

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

	friend Time operator+(const Time& t1,const Time& t2);
	friend Time operator-(const Time& t1, const Time& t2);
	friend Time operator*(const Time& t,double n);
	friend Time operator*(double m, const Time& t);
	friend std::ostream& operator << (std::ostream& os,const Time& time);

private:
	int hours;
	int minutes;
};


#endif // !TEXT4_H_

