#ifndef COMPLEX0_H_
#define COMPLEX0_H_

#include <iostream>

class complex
{
public:
	complex();
	complex(double a, double b);

	complex operator+(const complex& num) const;
	complex operator-(const complex& num) const;
	complex operator*(const complex& num) const;
	complex operator*(double x) const;
	complex operator~() const;

	friend complex operator*(double x, const complex& num) {
		return num * x;
	}


	friend std::ostream& operator<< (std::ostream& os, const complex& num);
	friend std::istream& operator>> (std::istream& os, complex& num);

private:
	double real;
	double imag;
};




#endif // !COMPLEX0_H_

