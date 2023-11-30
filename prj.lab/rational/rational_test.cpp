#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <rational/rational.h>
#include <doctest/doctest.h>
#include <sstream>
#include <vector>

void Equal(const Rational& drob,
    int chis, int znam) {
    REQUIRE((drob.upper == chis));
    REQUIRE((drob.downer == znam));
}

TEST_CASE("testing rational constructor") {
    Equal(Rational(4), 4, 1);

    Equal(Rational(0, 20), 0, 1);

    Equal(Rational(20, -1), -20, 1);

    Equal(Rational(-16, -6), 8, 3);

    Equal(Rational(-62), -62, 1);

    Equal(Rational(25, -5), -5, 1);

    Equal(Rational(6, 3), 2, 1);
}

TEST_CASE("exceptions")
{
    CHECK_THROWS(Rational(2, 44) / Rational(0, 17));
    CHECK_THROWS(Rational(99, 0));
}

TEST_CASE("prisvaivanie test")
{
    Rational drob_1 = Rational(2);
    Rational drob_2 = -Rational(drob_1);
    REQUIRE(drob_2.upper == -drob_1.upper);
    REQUIRE(drob_2.upper == -drob_1.upper);
}

TEST_CASE("prisvaivanie test")
{
    Rational drob_1 = Rational(2);
    Rational drob_2 = Rational(drob_1);
    REQUIRE(drob_1.upper == drob_2.upper);
    REQUIRE(drob_1.upper == drob_2.upper);
}

TEST_CASE("Assignment of Rational value to Complex test") {
    Rational a = Rational(2);
    Rational b = a;
    CHECK(b.upper == doctest::Approx(a.upper));
    REQUIRE(b.downer == doctest::Approx(a.downer));
}

TEST_CASE("+ test") {
    Rational drob_1 = Rational(1, 6);
    Rational drob_2 = Rational(1, 6);
    Rational drob_3 = Rational(1, 6);
    Rational final;
    final = drob_1 + drob_2 + drob_3;
    REQUIRE((final == Rational(1, 2)));
}



TEST_CASE("+= test") {
    Rational a = Rational();
    Rational b = Rational(1, 5);
    a += b;
    REQUIRE((a == Rational(1, 5)));
}

TEST_CASE("-= test") {
    Rational a = Rational();
    Rational b = Rational(1, 5);
    a -= b;
    REQUIRE((a == Rational(-1, 5)));
}

TEST_CASE("- test") {
    Rational drob_1 = Rational(4, 6);
    Rational drob_2 = Rational(1, 6);
    Rational drob_3 = Rational(1, 6);
    Rational final;
    final = drob_1 - drob_2 - drob_3;
    REQUIRE((final == Rational(1, 3)));
}

TEST_CASE("/ test") {
    Rational drob_1 = Rational(4, 6);
    Rational drob_2 = Rational(1, 6);
    Rational drob_3 = Rational(1, 6);
    Rational final;
    final = drob_1 / drob_2 / drob_3;
    REQUIRE((final == Rational(24, 1)));
}

TEST_CASE("* test") {
    Rational drob_1 = Rational(1, 6);
    Rational drob_2 = Rational(2, 6);
    Rational drob_3 = Rational(3, 6);
    Rational final;
    final = drob_1 * drob_2 * drob_3;
    REQUIRE((final == Rational(1, 36)));
}

TEST_CASE("*= test") {
    Rational a = Rational(2, 6);
    Rational b = Rational(1, 5);
    a *= b;
    REQUIRE((a == Rational(1, 15)));
}

TEST_CASE("/= test") {
    Rational drob_1 = Rational(1, 6);
    Rational drob_2 = Rational(-1, 5);
    drob_1 /= drob_2;
    REQUIRE((drob_1 == Rational(-5, 6)));
}

TEST_CASE("!= test") {
    Rational a = Rational();
    Rational b = Rational(2, 14);
    REQUIRE((a != b));
}

TEST_CASE("== test") {
    Rational a = Rational();
    Rational b = Rational(a);
    REQUIRE((a == b));
}

TEST_CASE("< test")
{
    Rational drob_1 = Rational(1, 5);
    Rational drob_2 = Rational(4, 10);
    REQUIRE((drob_1 < drob_2));
}

TEST_CASE("> test")
{
    Rational drob_1 = Rational(1, 5);
    Rational drob_2 = Rational(1, 10);
    REQUIRE((drob_1 > drob_2));
}

TEST_CASE("<= test")
{
    Rational drob_1 = Rational(1, 5);
    Rational drob_2 = Rational(2, 10);
    REQUIRE((drob_1 <= drob_2));
}

TEST_CASE(">= test")
{
    Rational drob_1 = Rational(1, 5);
    Rational drob_2 = Rational(2, 10);
    REQUIRE((drob_1 >= drob_2));
}

TEST_CASE("out") {
    std::stringstream stream;
    Rational drob = Rational(3, -19);
    stream << drob;
    std::string str;
    stream >> str;
    CHECK(str == "-3/19");
}

TEST_CASE("in") {
    std::stringstream potok("1/9  -5/5  19/1 0/100 -12/6 10/0 10/-0;");
    Rational test;
    potok >> test;
    CHECK((test == Rational(1, 9)));
    potok >> test;
    CHECK((test == Rational(-1, 1)));
    potok >> test;
    CHECK((test == Rational(19, 1)));
    potok >> test;
    CHECK((test == Rational(0, 100)));
    potok >> test;
    CHECK((test == Rational(-2, 1)));
    CHECK_THROWS((potok >> test));
    CHECK_THROWS((potok >> test));
}

TEST_CASE("[rational] - in/out") {
    std::stringstream correctStr("-2/6  1/2  2/1  0/7  -8/12   16/0  17/0");
    Rational correctRational[] = { Rational(-2, 6), Rational(1, 2), Rational(2, 1), Rational(0, 7), Rational(-8, 12) };
    Rational ioTest(1, 1);
    for (int i = 0; i < 5; i++) {
        correctStr >> ioTest;
        //std::cout << "\n\n" << ioTest << "\n\n";
        CHECK((ioTest == correctRational[i]));
    }
    CHECK_THROWS((correctStr >> ioTest));
    CHECK_THROWS((correctStr >> ioTest));

    std::stringstream outputTest;

    outputTest << correctRational[0];
    CHECK((outputTest.str() == "-1/3"));
    outputTest.str("");

    outputTest << correctRational[1];
    CHECK((outputTest.str() == "1/2"));
    outputTest.str("");

    outputTest << correctRational[2];
    CHECK((outputTest.str() == "2/1"));
    outputTest.str("");

    outputTest << correctRational[3];
    CHECK((outputTest.str() == "0/1"));
    outputTest.str("");

    outputTest << correctRational[4];
    CHECK((outputTest.str() == "-2/3"));
    outputTest.str("");
}