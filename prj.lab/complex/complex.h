#ifndef COMPLEX
#define COMPLEX

#include <iosfwd>
#include <stdexcept>
#include <limits>

struct Complex
{
private:

public:

    ~Complex() = default;

    //опертоаторы сравнения
    bool operator==(const Complex& drob_1) const;
    bool operator!=(const Complex& drob_1) const;

    double re = 0;
    double im = 0;

    //конструкторы
    Complex(double real, double image);
    Complex(double real);
    Complex();

    //методы
    bool isZero() const;
    double getModule() const;

    //сокращенные арифметоческие операторы
    Complex& operator=(const Complex& b);
    Complex& operator+=(const Complex& b);
    Complex& operator-=(const Complex& b);
    Complex& operator*=(const Complex& b);
    Complex& operator/=(const Complex& b);
    //ввод-вывод
    friend std::ostream& operator<<(std::ostream& ostream, const Complex& data);
    friend std::istream& operator>>(std::istream& istream, Complex& data);

    static constexpr double k2Eps{ 2.0 * std::numeric_limits<double>::epsilon() };

    static const char kLeftBracket{ '{' };
    static const char kSeparator{ ',' };
    static const char kRightBracket{ '}' };

    Complex operator+() const;
    Complex operator-() const;
};

//арифметоческие операторы
Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);

#endif
