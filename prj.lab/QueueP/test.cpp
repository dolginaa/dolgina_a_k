#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "QueueP.h"

TEST_CASE("Tests") {

	QueueP test;
	test.Push(5);
	test.Push(3);
	test.Push(2);
	test.Push(6);
	CHECK(test.Size() == 4);
	CHECK(test.Top() == 2);
	test.Pop();
	CHECK(test.Top() == 3);
	CHECK(test.Size() == 3);
	test.Push(1);
	CHECK(test.Size() == 4);
	CHECK(test.Top() == 1);
	test.Pop();
	CHECK(test.Top() == 3);
	CHECK(test.Size() == 3);
	test.Pop();
	CHECK(test.Top() == 5);
	test.Pop();
	CHECK(test.Top() == 6);
	test.Pop();
	CHECK(test.isEmpty() == true);
	CHECK(test.Size() == 0);
	CHECK_THROWS_WITH(test.Pop(), "Queue is empty");
	
	test.Push(1);
	test.Push(5);
	test.Push(12);
	test.Push(13);
	test.Push(5);
	
	QueueP test1;
	test1 = test;

	CHECK(test.Top() == test1.Top());
	CHECK(test.Size() == test1.Size());
	test.Pop();
	CHECK(test.Top() != test1.Top());
	CHECK(test.Size() == test1.Size() - 1);
	test.Clear();
	CHECK(test.Size() == 0);
	CHECK(test.isEmpty() == true);
	test.Push(5);
	test.Push(7);
	test.Push(3);
	test.Push(11);
	CHECK(test.Size() == 4);
	CHECK(test1.Size() == 5);
	test.Swap(test1);
	CHECK(test1.Size() == 4);
	CHECK(test.Size() == 5);
	CHECK(test1.Top() == 3);
	CHECK(test.Top() == 1);

	QueueP test2(test);
	CHECK(test2.Top() == test.Top());
	CHECK(test2.Size() == test.Size());
	test2.Pop();
	CHECK(test2.Top() != test.Top());
	CHECK(test2.Size() == test.Size() - 1);

	QueueP test3;
	QueueP test4(test3);
	CHECK(test4.isEmpty() == true);
	test4.Push(1);
	CHECK(test4.Top() == 1);
	CHECK(test3.isEmpty() == true);
	

}
