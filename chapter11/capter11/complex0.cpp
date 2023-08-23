#include "complex0.h"


complex::complex(double a, double b)
{
    real = a;
    imag = b;
}

complex::complex()
{
    real = 0.0;
    imag = 0.0;
}

complex complex::operator+(const complex& num) const {
    return complex(real + num.real, imag + num.imag);
}


complex complex::operator-(const complex& num) const {
    return complex(real - num.real, imag - num.imag);
}


complex complex::operator*(const complex& num) const {
    return complex(real * num.real - imag * num.imag,
        real * num.imag + num.real * imag);
}

complex complex::operator*(double x) const {
    return complex(x * real, x * imag);
}

complex complex::operator~() const
{
    return complex(real,-imag);
}

std::ostream& operator<< (std::ostream& os, const complex& num) {
    os << "(" << num.real << "," << num.imag << "i)";
    return os;
}

std::istream& operator>> (std::istream& in,complex& num) {
    std::cout << "real: ";
    in >> num.real;
    std::cout << "imaginary: ";
    in >> num.imag;
    return in;
}
