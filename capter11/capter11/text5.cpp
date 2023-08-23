
#include <iostream>
#include "text5.h"

using std::cout;

Stonewt::Stonewt(double lbs,Mode m) {
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
	mode = m;
}

Stonewt::Stonewt(int stn, double lbs,  Mode m) {
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
	mode = m;
}

Stonewt::Stonewt() {
	stone = pounds = pds_left = 0;
	mode = ST;
}

Stonewt::~Stonewt()
{

}

Stonewt Stonewt::operator*(double mul) const {
	return Stonewt(mul * pounds);
}
Stonewt Stonewt::operator+(const Stonewt& st) const {
	return Stonewt(pounds + st.pounds);
}
Stonewt Stonewt::operator-(const Stonewt& st) const {
	return Stonewt(pounds - st.pounds);
}

std::ostream& operator<<(std::ostream& os, const Stonewt& st)
{
	if (st.mode == Stonewt::Mode::ST) 
	{
		os << st.stone << " stone, " << st.pds_left << " pounds";
	}
	else if (st.mode == Stonewt::Mode::POUND)
	{
		os << int(st.pounds + 0.5) << " pounds";
	}
	else if (st.mode == Stonewt::Mode::POUND_F)
	{
		os << st.pounds << " pounds";
	}
	else
	{
		os << "Mode error!";
	}
	return os;
}
