/*
@Author: mrxhar
@Date:   2023-08-24 15:57:14
@Email:  1337904145@qq.com
@Blog:
*/
#include <iostream>
#include <stdexcept> // 异常类
#include <string>

class Sales
{


public:
    enum
    {
        MONTHS = 12
    };
    class bad_index : public std::logic_error // 继承及嵌套
    {
    private:
        int bi;

    public:
        explicit bad_index(int ix, const std::string &s = "Index error in Sales object\n");
        int bi_val() const
        {
            return bi;
        };
        virtual ~bad_index() throw(){}; // 虚析构 并且异常
    };

    explicit Sales(int yy = 0);
    Sales(int yy, const double *gr, int n);
    virtual ~Sales(){};
    int Year() const { return year; };
    virtual double operator[](int i) const;
    virtual double &operator[](int i);

private:
    double gross[MONTHS];
    int year;
};

class LabeledSales : public Sales // 继承 一个 ：
{
public:
    class nbad_index : public Sales::bad_index // 继承嵌套
    {
    private:
        std::string lbl;

    public:
        nbad_index(const std::string &lb, int lx, const std::string &s = "Index error in LabeledSales object\n");
        const std::string &label_val() const { return lbl; };
        virtual ~nbad_index() throw(){};
    };

    explicit LabeledSales(const std::string &lb = "none", int yy = 0);
    LabeledSales(const std::string &lb, int yy, const double *gr, int n);
    virtual ~LabeledSales(){};
    const std::string &Label() const
    {
        return label;
    };
    virtual double operator[](int i) const;
    virtual double &operator[](int i);

private:
    std::string label;
};