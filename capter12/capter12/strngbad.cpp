#include <cstring>
#include "strngbad.h"

using std::cout;

int StringBad::num_strings = 0; 
// 初始化为0 不能在类声明中进行定义，会造成每次声明都会重新初始化。

StringBad::StringBad(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
	cout << num_strings << ":\"" << str << "\" object created\n";
}

std::ostream& operator<<(std::ostream& os, const StringBad& st)
{
	os << st.str;
	return os;
}

StringBad::StringBad()
{
	len = 4;
	str = new char[4];
	strcpy(str, "C++");
	num_strings++;
	std::cout << num_strings << ": \"" << str << "\" default object created\n";
}

StringBad::~StringBad()
{
	std::cout << "\"" << str << "\" object deleted, ";
	--num_strings;
	std::cout << num_strings << " left.\n";
	delete[] str;
}