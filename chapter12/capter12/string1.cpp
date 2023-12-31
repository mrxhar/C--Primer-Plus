#include "string1.h"
#include <cstring>
#include "string2.h"
using std::cout;
using std::cin;



int String::num_strings = 0; // 静态变量初始化不能在类声明中

String::String(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
}

String::String()
{
	len = 1;
	str = new char[1]; // 为了和析构函数一致
	str[0] = '\0';
	num_strings++;
}

String::String(const String& st )
{
	// 复制运算符
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}

String::~String()
{
	// 释放内存
	num_strings--;
	delete[] str;
}

String& String::operator=(const String& st)
{
	// 赋值运算，深赋值
	if (this == &st)
	{
		return *this;
	}
	delete[] str; // 清空内存
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

String& String::operator=(const char* st)
{
	delete[] str; // 清空内存
	len = strlen(st);
	str = new char[len + 1];
	std::strcpy(str, st);
	return *this;
}

char& String::operator[](int i)
{
	return str[i];
}

const char& String::operator[](int i) const
{
	return str[i];
}

int String::HowMany()
{
	return num_strings;
}

bool operator<(const String& st1, const String& st2)
{
	// 对比
	return (std::strcmp(st1.str, st2.str) < 0 ); // strcmp 字符串比较函数
}

bool operator>(const String& st1, const String& st2)
{
	return st2 < st1;
}

bool operator==(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

ostream& operator<<(ostream& os, const String& st)
{
	os << st.str;
	return os;
}

istream& operator>>(istream& in, String& st)
{
	// 输入赋值比较麻烦
	char temp[String::CINLIM];
	in.get(temp, String::CINLIM);
	// 然后生成性的变量
	if (in) // 输入成功
	{
		st = temp;
	}
	while (in && in.get() != '\n')
	{
		continue;
	}
	return in;
}
