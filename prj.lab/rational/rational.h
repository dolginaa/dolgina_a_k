#pragma once
#ifndef RATIONAL_RATIONAL_H_20220309
#define RATIONAL_RATIONAL_H_20220309
#include <iostream>
class Rational {
public:

    int upper=0;
    int downer=1;
    static const char separator = '/';

    Rational(int up, int down);
    Rational(int up);
    Rational();

    bool null() const;
    void reduce(int up, int down);

    bool operator<(const Rational& frac_1) const;
    bool operator<=(const Rational& frac_1) const;
    bool operator==(const Rational& frac_1) const;
    bool operator>(const Rational& frac_1) const;
    bool operator>=(const Rational& frac_1) const;
    bool operator!=(const Rational& frac_1) const;

    Rational& operator=(const Rational& znach);
    Rational& operator+=(const Rational& znach);
    Rational& operator-=(const Rational& znach);
    Rational& operator*=(const Rational& znach);
    Rational& operator/=(const Rational& znach);

    Rational operator+(const Rational& frac_1);
    Rational operator-(const Rational& frac_1);
    Rational operator*(const Rational& frac_1);
    Rational operator/(const Rational& frac_1);

    Rational operator-();
    Rational operator+();

    static const char leftBrace{ '{' };
    static const char separtor{ '/' };
    static const char rightBrace{ '}' };

    friend std::ostream& operator<<(std::ostream& ostream, const Rational& data);
    friend std::istream& operator>>(std::istream& istream, Rational& data);
};

#endif