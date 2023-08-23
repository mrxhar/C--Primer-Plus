#ifndef STRNGBAD_H_
#define STRNGBAD_H_

#include <iostream>
#include <string>

#pragma warning( disable : 4996)

class StringBad
{
public:
	StringBad();
	~StringBad();
	StringBad(const char* s);// 使用指针的构造函数
	friend std::ostream& operator<<(std::ostream& os, const StringBad& st);

private:
	char* str;
	int len;
	static int num_strings; // 静态变量 所有类共享
};



#endif // !STRNGBAD_H_


