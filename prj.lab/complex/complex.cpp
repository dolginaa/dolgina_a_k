#include "Complex.h"
#include <cmath>
#include <iostream>
//конструкторы
Complex::Complex(double real, double image)
{
    this->re = real;
    this->im = image;
}

Complex::Complex(double real)
{
    this->re = real;
    this->im = 0;
}

Complex::Complex()
{
    this->re = 0;
    this->im = 0;
}
//методы
bool Complex::isZero() const
{
    if (re == 0 && im == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double Complex::getModule() const {
    return sqrt(re * re + im * im);
}

// арифметческие опреаторы
Complex& Complex::operator=(const Complex& other)
{
    re = other.re;
    im = other.im;
    return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.re + rhs.re, lhs.im + rhs.im);
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.re * rhs.re - lhs.im * rhs.im, lhs.im * rhs.re + lhs.re * rhs.im);
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{

    if (rhs.isZero())
    {
        throw  "Division error by zero!";
    }
    //if (rhs.isZero())
    //{
    //    throw std::runtime_error("Attempted to divide by Zero\n");
    //}
    else
    {
        return Complex((lhs.re * rhs.re + lhs.im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im), (lhs.im * rhs.re - lhs.re * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im));
    }
}
//скоращенные арифметические операторы
Complex& Complex::operator/=(const Complex& other)
{
    if (other.isZero())
    {
        throw  "Division error by zero!";
    }
    //if (other.isZero())
    //{
    //    throw std::runtime_error("Attempted to divide by Zero\n");
    //}

    double real_temp;
    double image_temp;
    real_temp = (re * other.re + im * other.im) / (other.re * other.re + other.im * other.im);
    image_temp = (im * other.re - re * other.im) / (other.re * other.re + other.im * other.im);
    re = real_temp;
    im = image_temp;
    return *this;
}

Complex& Complex::operator+=(const Complex& chis)
{
    re += chis.re;
    im += chis.im;
    return *this;
}

Complex& Complex::operator*=(const Complex& other)
{
    double real_temp;
    double image_temp;
    real_temp = (re * other.re) - (im * other.im);
    image_temp = (im * other.re) + (re * other.im);
    re = real_temp;
    im = image_temp;
    return *this;
}

Complex& Complex::operator-=(const Complex& chis)
{
    re -= chis.re;
    im -= chis.im;
    return *this;
}

bool Complex::operator==(const Complex& other)const
{
    return std::abs(re - other.re) < k2Eps && std::abs(im - other.im) < k2Eps;
}

bool Complex::operator!=(const Complex& other)const
{
    return !(operator==(other));
}

Complex Complex::operator-() const
{
    return Complex{ -re, -im };
}

Complex Complex::operator+() const
{
    return (*this);
}
//ввод-вывод
std::ostream& operator<<(std::ostream& ostream, const Complex& data) {
    ostream << data.kLeftBracket << data.re << data.kSeparator <<
        data.im << data.kRightBracket;
    return ostream;
}

std::istream& operator>>(std::istream& istream, Complex& data) {
    char left_bracket;
    double real;
    char separator;
    double imaginary;
    char right_bracket;
    istream >> left_bracket >> real >> separator >> imaginary >> right_bracket;
    if (istream.good()) {
        if (left_bracket == Complex::kLeftBracket && separator == Complex::kSeparator && right_bracket == Complex::kRightBracket)
        {
            data.re = real;
            data.im = imaginary;
        }
        else
        {
            istream.setstate(std::ios_base::failbit);
        }
    }
    return istream;
}