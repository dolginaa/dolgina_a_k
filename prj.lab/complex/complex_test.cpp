#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <complex/complex.h>
#include <doctest/doctest.h>
#include <string>
#include <sstream>
#include <vector>

TEST_CASE("prisvaivanie test")
{
    Complex chis_1 = Complex(2);
    Complex chis_2 = Complex(chis_1);
    REQUIRE(chis_1.re == chis_2.re);
    REQUIRE(chis_1.im == chis_2.im);
}

TEST_CASE("Assignment of Complex value to Complex test") {
    Complex a = Complex(2);
    Complex b = a;
    CHECK(b.re == doctest::Approx(a.re));
    REQUIRE(b.im == doctest::Approx(a.im));
}

TEST_CASE("+ test") {
    Complex chis_1 = Complex(1, 6);
    Complex chis_2 = Complex(1, 4);
    Complex chis_3 = Complex(1, 5);
    Complex final;
    final = chis_1 + chis_2 + chis_3;
    REQUIRE((final == Complex(3, 15)));
}

TEST_CASE("- test") {
    Complex chis_1 = Complex(4, 6);
    Complex chis_2 = Complex(1, 6);
    Complex chis_3 = Complex(1, 6);
    Complex final;
    final = chis_1 - chis_2 - chis_3;
    REQUIRE((final == Complex(2, -6)));
}

TEST_CASE("/ test") {
    Complex drob_1 = Complex(4, 6);
    Complex drob_2 = Complex(2, 6);
    Complex final;
    final = drob_1 / drob_2;
    REQUIRE((final == Complex(1.1, -0.3)));
}

TEST_CASE("* test") {
    Complex drob_1 = Complex(1, 6);
    Complex drob_2 = Complex(2, 6);
    Complex final;
    final = drob_1 * drob_2;
    REQUIRE((final == Complex(-34, 18)));
}

TEST_CASE("+= test") {
    Complex a = Complex();
    Complex b = Complex(1, 5);
    a += b;
    REQUIRE((a == Complex(1, 5)));
}

TEST_CASE("-= test") {
    Complex a = Complex();
    Complex b = Complex(1, 5);
    a -= b;
    REQUIRE((a == Complex(-1, -5)));
}

TEST_CASE("*= test") {
    Complex a = Complex(1, 6);
    Complex b = Complex(2, 6);
    a *= b;
    REQUIRE((a == Complex(-34, 18)));
}

TEST_CASE("/= test") {
    Complex drob_1 = Complex(4, 6);
    Complex drob_2 = Complex(2, 6);
    drob_1 /= drob_2;
    REQUIRE((drob_1 == Complex(1.1, -0.3)));
}

TEST_CASE("!= test") {
    Complex a = Complex(1, 3);
    Complex b = Complex(2, 14);
    REQUIRE((a != b));
}

TEST_CASE("== test") {
    Complex a = Complex();
    Complex b = Complex(a);
    REQUIRE((a == b));
}

TEST_CASE("testing complex constructors") {
    CHECK_NOTHROW(Complex(7.1, 3.5));
    CHECK_NOTHROW(Complex(7.2, -3.6));
    CHECK_NOTHROW(Complex(-7.3, 3.7));
    CHECK_NOTHROW(Complex(-7.4, -3.8));
    CHECK_NOTHROW(Complex(4.2));
    CHECK_NOTHROW(Complex(-4.3));
    CHECK_NOTHROW(Complex());
    CHECK_NOTHROW(Complex(Complex(1.3, 2.7)));
}

TEST_CASE("exceptions")
{
    CHECK_THROWS(Complex(2, 44) / Complex(0, 0));
}

TEST_CASE("testing complex In Out") {
    std::vector<std::stringstream*> correct_inputs{ new std::stringstream("{1.2,3.4}"),
                                                     new std::stringstream("{-1.2, 3.4}"),
                                                     new std::stringstream("{1.2, -3.4}"),
                                                     new std::stringstream("{-1.2, -3.4}") };
    std::vector<Complex> inputs_complex{ Complex(1.2, 3.4),
                                         Complex(-1.2,  3.4),
                                         Complex(1.2,  -3.4),
                                         Complex(-1.2,  -3.4) };

    for (int64_t i = 0; i < correct_inputs.size(); ++i) {
        Complex input{ 1, 1 };
        *(correct_inputs[i]) >> input;
        CHECK(input == inputs_complex[i]);
    }

    for (auto it : correct_inputs) {
        delete it;
    }
}

//#include <complex/complex.h>
//#include <iostream>

//int main()
//{
//	Complex g(6, 3);
//	Complex o(0, 0);
//	TestDibByZero(g, o);
//}