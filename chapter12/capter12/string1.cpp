#include "string1.h"
#include <cstring>
#include "string2.h"
using std::cout;
using std::cin;



int String::num_strings = 0; // ��̬������ʼ����������������

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
	str = new char[1]; // Ϊ�˺���������һ��
	str[0] = '\0';
	num_strings++;
}

String::String(const String& st )
{
	// ���������
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}

String::~String()
{
	// �ͷ��ڴ�
	num_strings--;
	delete[] str;
}

String& String::operator=(const String& st)
{
	// ��ֵ���㣬�ֵ
	if (this == &st)
	{
		return *this;
	}
	delete[] str; // ����ڴ�
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

String& String::operator=(const char* st)
{
	delete[] str; // ����ڴ�
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
	// �Ա�
	return (std::strcmp(st1.str, st2.str) < 0 ); // strcmp �ַ����ȽϺ���
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
	// ���븳ֵ�Ƚ��鷳
	char temp[String::CINLIM];
	in.get(temp, String::CINLIM);
	// Ȼ�������Եı���
	if (in) // ����ɹ�
	{
		st = temp;
	}
	while (in && in.get() != '\n')
	{
		continue;
	}
	return in;
}