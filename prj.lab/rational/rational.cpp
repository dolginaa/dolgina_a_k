#include "rational.h"
#include <iostream>
//конструкторы
Rational::Rational(int up, int down) {
    if (down==0)
    {
        throw"oshibka deleniya na nol";
    }
    if (up==0)
    {
        down = 1;
    }
    if ((up*down) < 0)
    {
        this->upper = -abs(up);
        this->downer = abs(down);
    }
    else
    {
        this->upper = abs(up);
        this->downer = abs(down);
    }

    reduce(this->upper, this->downer);

}

Rational::Rational(int up) {
    this->upper = up;
    this->downer = 1;
}

Rational::Rational() {
    this->upper = 0;
    this->downer = 1;
}
//методы
bool Rational::null() const
{
        return(downer==0);
}

void Rational::reduce(int up, int down)
{
    if (abs(upper) > abs(downer))
    {
        for (int i = abs(downer); i >= 2; i--)
        {
            if ((abs(upper) % i == 0) && (abs(downer) % i == 0))
            {
                upper /= i;
                downer /= i;
            }
        }
    }
    else
    {
        for (int i = abs(upper); i >= 2; i--)
        {
            if ((abs(downer) % i == 0) && (abs(upper) % i == 0))
            {
                downer = downer / i;
                upper = upper / i;
            }
        }
    }
}

Rational Rational::operator-()
{
    return Rational{ -upper, downer };
}
Rational Rational::operator+()
{
    return Rational{ upper, downer };
}
//сокращенные арифметические операторы
Rational& Rational::operator=(const Rational& frac)
{
    upper = frac.upper;
    downer = frac.downer;
    return *this;
}

Rational& Rational::operator+=(const Rational& frac)
{
    upper = (upper * frac.downer) + (frac.upper * downer);
    downer = downer * frac.downer;
    reduce(upper, downer);
    return *this;
}

Rational& Rational:: operator*=(const Rational& frac)
{
    upper = upper * frac.upper;
    downer = downer * frac.downer;
    reduce(upper, downer);
    return *this;
}

Rational& Rational:: operator/=(const Rational& frac)
{
    if (frac.downer == 0)
    {
        throw"oshibka deleniya na nol";
    }
    upper = upper * frac.downer;
    downer = downer * frac.upper;
    reduce(upper, downer);
    return *this;
}

Rational& Rational:: operator-=(const Rational& frac)
{
    upper = (upper * frac.downer) - (frac.upper * downer);
    downer = downer * frac.downer;
    reduce(upper, downer);
    return *this;
}
//обычные арифметические операторы
Rational Rational:: operator+(const Rational& frac_1)
{
    return Rational(upper * frac_1.downer + (downer * frac_1.upper), downer * frac_1.downer);
}

Rational Rational:: operator-(const Rational& frac_1)
{
    return Rational(upper * frac_1.downer - downer * frac_1.upper, downer * frac_1.downer);
}

Rational Rational:: operator*(const Rational& frac_1)
{
    return Rational(upper * frac_1.upper, downer * frac_1.downer);
}

Rational Rational:: operator/(const Rational& frac_1)
{
    return Rational(upper * frac_1.downer, downer * frac_1.upper);
}
//операторы ввода-вывода

std::ostream& operator<<(std::ostream& ostream, const Rational& data) {
    ostream << data.upper << data.separator << data.downer;
    return ostream;
}

std::istream& operator >> (std::istream& istr, Rational& drob) {
    istr >> drob.upper;
    char separator('  ');
    istr >> std::noskipws;
    if (istr.peek() != '/') {
        istr.setstate(std::ios_base::failbit);
    }
    istr >> separator;
    if (istr.peek() == '-' || istr.peek() == ' ') {
        istr.setstate(std::ios_base::failbit);
    }
    istr >> drob.downer >> std::skipws;
    if (drob.downer == 0)
    {
        throw(std::exception("Division error by zero!"));
    }
    drob.reduce(drob.upper, drob.downer);
    return istr;
}

//операторы сравнения
bool Rational::operator==(const Rational& other_frac) const
{
    return ((upper * other_frac.downer) == (other_frac.upper * downer));
}

bool Rational::operator!=(const Rational& other_frac) const
{
    return !(operator==(other_frac));
}

bool Rational::operator<(const Rational& other_frac) const
{
    return ((upper * other_frac.downer) < (other_frac.upper * downer));
}

bool Rational::operator>(const Rational& other_frac) const
{
    return ((upper * other_frac.downer) > (other_frac.upper * downer));
}

bool Rational::operator<=(const Rational& other_frac) const
{
    return ((upper * other_frac.downer) <= (other_frac.upper * downer));
}

bool Rational::operator>=(const Rational& other_frac) const
{
    return ((upper * other_frac.downer) >= (other_frac.upper * downer));
}