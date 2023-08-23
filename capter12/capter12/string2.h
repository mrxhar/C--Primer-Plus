#ifndef STRING2_H_
#define STRING2_H_

#include <iostream>
#include <cctype>
using std::ostream;
using std::istream;

#pragma warning( disable : 4996)


class String
{
public:
	// ���캯��
	String(const char* s);
	String();
	String(const String&); // ���ƺ���
	~String();
	int length() const { return len; } // inline ����������String ����
	// ���������
	String& operator=(const String&); // ��ֵ����
	String& operator=(const char*);
	char& operator[](int i);
	const char& operator[](int i) const; // ��̬����
	//�������Ԫ����
	friend bool operator<(const String& st, const String& st2);
	friend bool operator>(const String& st, const String& st2);
	friend bool operator==(const String& st, const String& st2);
	friend ostream& operator<<(ostream& os, const String& st);
	friend istream& operator>>(istream& in, String& st);
	friend String operator+(const String& s1, const String& s2); // ������Ҫͬһ����ʱ���������ܷ���Ϊ ����
	// ��Ա���� 
	void stringlow();
	void stringup();
	int has(const char ch) const;
	// ��̬����
	static int HowMany();

private:
	char* str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
};


#endif // !STRING_H_
