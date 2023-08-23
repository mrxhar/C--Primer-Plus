#ifndef __TEXT6__H__
#define __TEXT6__H__

#include <iostream>

using namespace std;

class Move
{
public:
	Move(double a = 0, double b = 0);
	void showmove()const;
	Move add(const Move& m);
	void reset(double a = 0, double b = 0);

private:
	double x;
	double y;
};



#endif // !__TEXT6__H__

