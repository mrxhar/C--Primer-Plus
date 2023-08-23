/*
@Author: mrxhar
@Date:   2023-08-22 11:28:28
@Email:  1337904145@qq.com
@Blog:   
*/

#ifndef __STUDENTI__H__
#define __STUDENTI__H__

#include <iostream>
#include <valarray>
#include <string>

class Student:private std::string ,private std::valarray<double>
{
private:
    typedef std::valarray<double> ArrayDb;
    std::ostream &arr_out(std::ostream &os) const;

public:
    Student() : std::string("Null Student"), ArrayDb() {}
    explicit Student(const std::string &s) : std::string(s), ArrayDb(){}; // 防止隐式转换。 单参数的时候
    explicit Student(int n) : std::string("Null Student"), ArrayDb(n){};
    Student(const std::string &s, int n) : std::string(s), ArrayDb(n){};
    Student(const std::string &s, const ArrayDb &a) : std::string(s), ArrayDb(a){};
    Student(const char *str, const double *pd, int n) : std::string(str), ArrayDb(pd, n){};
    ~Student(){};
    double Average() const;
    const std::string& Name() const;
    double operator[](int i) const;
    double &operator[](int i); // 可以进行赋值的

    // friend
    friend std::istream &operator>>(std::istream &is, Student &stu);
    friend std::istream &getline(std::istream &is, Student &stu);
    friend std::ostream &operator<<(std::ostream &os, const Student &stu);
};

#endif