#ifndef TEXT5_H_
#define  TEXT5_H_

#include<iostream>

class Stonewt
{
public:
	enum Mode{ST,POUND,POUND_F}; // 使用枚举定义其状态

	Stonewt(double lbs,Mode m = ST);
	Stonewt(int stn, double lbs, Mode m = ST);
	Stonewt();
	~Stonewt();
	//void show_lbs() const;
	//void show_stn() const;

	void set_ST() { mode = ST; }
	void set_POUND() { mode = POUND; }
	void set_POUND_F() { mode = POUND_F; }

	Stonewt operator*(double mul) const;
	Stonewt operator+(const Stonewt& st) const;
	Stonewt operator-(const Stonewt& st) const;

	friend Stonewt operator* (double mul, const Stonewt& st) {
		return st * mul;
	}
	friend std::ostream & operator<< (std::ostream& os, const Stonewt& st);

private:	
	enum {Lbs_per_stn = 14};
	int stone;
	double pds_left;
	double pounds;
	Mode mode;
};



#endif // !TEXT5_H_

