#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <bitset/bitset.h>
#include <doctest/doctest.h>
#include <sstream>
#include <string>
#include <vector>


TEST_CASE("[bitset] - bitset ctor") {
	CHECK(Bitset("1111111") == Bitset(7, true));
	CHECK(Bitset("0000000") == (Bitset(7, true) << 10));
	CHECK(Bitset("0000000") == (Bitset(7, true) >> 7));
	CHECK(Bitset("0101010") == ~Bitset("1010101"));
	CHECK(Bitset(10) == ~Bitset(Bitset(10, true)));
	CHECK_THROWS(Bitset(-1) == Bitset(0));
	CHECK_THROWS(Bitset("123321321123"));
}

TEST_CASE("[bitset] - operators") {
	CHECK(Bitset(123) != Bitset(122));
	CHECK(Bitset(123) == Bitset(123));
	Bitset a = Bitset("101010101"), b;
	b = a;
	CHECK(a == b);
	a.resize(15, true);
	CHECK(a != b);
	a.resize(b.size());
	CHECK(a == b);
	a.fill(true);
	a &= b;
	a |= b;
	CHECK(a == b);
	a ^= b;
	b.fill(false);
	CHECK(a == b);
	a.resize(100);
	CHECK_THROWS(a ^= b);
	CHECK_THROWS(a |= b);
	CHECK_THROWS(a &= b);
	a = Bitset("10101010101");
	b = Bitset("01010101010");
	CHECK(a == ~b);
	Bitset c = Bitset("01010101010");
	CHECK(b.size() == 11);
	CHECK((a & b) == Bitset("00000000000"));
	CHECK((a | b) == Bitset("11111111111"));
	CHECK((a ^ b) == Bitset("11111111111"));
	CHECK((b ^ c) == Bitset("00000000000"));
	a >>= 2;
	CHECK(a == Bitset("00101010101"));
	a <<= 2;
	CHECK(a == Bitset("10101010100"));
	a >>= 1;
	CHECK(a == Bitset("01010101010"));
	a >>= 0;
	a <<= 0;
	CHECK_THROWS(a >>= -1);
	CHECK_THROWS(a <<= -1);
	CHECK_THROWS(a << -1);
	CHECK_THROWS(a >> -1);
	CHECK_THROWS(Bitset(1)[5]);
	CHECK_THROWS(Bitset(1)[1]);
	CHECK(a == Bitset("01010101010"));
	CHECK(Bitset(123) == Bitset(123));
}

TEST_CASE("[bitset] - input_output") {
	std::stringstream input("111011101100011");
	Bitset a;
	input >> a;
	CHECK(a == Bitset("111011101100011"));
}