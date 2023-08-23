#pragma once
#ifndef __PLORG__H__
#define __PLORG__H__

#include <iostream>
#include <cstring>

const int SIZE = 19;
class Plorg
{
private:
	char name[SIZE];
	int CI;
public:
	Plorg(const char* str = "Plorga", int ci = 50);
	void reset(int ci);
	void show() const;
};

#endif // !__PLORG__H__