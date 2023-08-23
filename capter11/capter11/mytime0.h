#ifndef MYTIME0_H_
#define MYTIME1_H_

const int H_to_M = 60;

class Time
{
public:
	Time();
	Time(int h, int m = 0);
	void Addmin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	Time Sum(const Time& t) const;
	void Show() const;

private:
	int hours;
	int minutes;
};


#endif // !MYTIME0_H_

