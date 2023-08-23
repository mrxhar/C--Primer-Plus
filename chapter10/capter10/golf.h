#ifndef __GOLF__H__
#define __GOLF__H__

#include <iostream>

const int Len = 40;
class golf
{
public:
	golf(const char* name,int hc);
	golf();
	void sethandicap(int hc);
	void showgolf() const;

private:
	char fullname[Len];
	int handicap;
};

#endif // !__GOLF__H__

