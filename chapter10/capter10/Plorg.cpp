#include "Plorg.h"

Plorg::Plorg(const char* str, int ci) {
	strcpy_s(name, str);
	CI = ci;
}

void Plorg::reset(int ci) {
	CI = ci;
}

void Plorg::show() const{
	std::cout << "Name: " << name << ", CI = " << CI << std::endl;
}