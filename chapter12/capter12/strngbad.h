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
	StringBad(const char* s);// ʹ��ָ��Ĺ��캯��
	friend std::ostream& operator<<(std::ostream& os, const StringBad& st);

private:
	char* str;
	int len;
	static int num_strings; // ��̬���� �����๲��
};



#endif // !STRNGBAD_H_


