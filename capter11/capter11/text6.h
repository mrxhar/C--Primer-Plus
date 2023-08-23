#ifndef TEXT_H_
#define  TEXT_H_

class Stonewt
{
public:
	Stonewt(double lbs);
	Stonewt(int stn, double lbs);
	Stonewt();
	~Stonewt();
	void show_lbs() const;
	void show_stn() const;

	bool operator>(const Stonewt& st) const;
	bool operator>=(const Stonewt& st) const;
	bool operator<(const Stonewt& st) const;
	bool operator<=(const Stonewt& st) const;
	bool operator==(const Stonewt& st) const;
	bool operator!=(const Stonewt& st) const;



private:
	enum {Lbs_per_stn = 14};
	int stone;
	double pds_left;
	double pounds;
};



#endif // !TEXT_H_

