#ifndef STRING_H_
#define STRING_H_

#include <iostream>
using std::ostream;
using std::istream;

#pragma warning( disable : 4996)


class String
{
public:
	// 构造函数
	String(const char* s);
	String();
	String(const String&); // 复制函数
	~String();
	int length() const { return len; } // inline 函数，返回String 长度
	// 重载运算符
	String& operator=(const String&); // 赋值函数
	String& operator=(const char*); 
	char& operator[](int i);
	const char& operator[](int i) const; // 静态重载
	//运算符友元函数
	friend bool operator<(const String& st, const String& st2);
	friend bool operator>(const String& st, const String& st2);
	friend bool operator==(const String& st, const String& st2);
	friend ostream& operator<<(ostream& os, const String& st);
	friend istream& operator>>(istream& in, String& st);
	// 静态函数
	static int HowMany();

private:
	char* str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
};


#endif // !STRING_H_
