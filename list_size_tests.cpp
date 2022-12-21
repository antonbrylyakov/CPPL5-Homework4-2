#include <catch2/catch_test_macros.hpp>
#include "list.h"

TEST_CASE("New list is empty", "[list]") {
	List list;
	CHECK(list.Empty() == true);
	CHECK(list.Size() == 0);
}

TEST_CASE("Cleared list is empty", "[list]") {
	List list;
	list.PushBack(1);
	list.PushBack(2);
	list.Clear();
	CHECK(list.Empty() == true);
	CHECK(list.Size() == 0);
}

// Тест-кейсы на добавление элементов разными способами

TEST_CASE("Correct number of items", "[list]") {

	SECTION("Push back 2 times")
	{
		List list;
		REQUIRE(list.Size() == 0);
		list.PushBack(1);
		REQUIRE(list.Size() == 1);
		list.PushBack(2);
		REQUIRE(list.Size() == 2);
	}

	SECTION("Push front 2 times")
	{
		List list;
		REQUIRE(list.Size() == 0);
		list.PushFront(1);
		REQUIRE(list.Size() == 1);
		list.PushFront(2);
		REQUIRE(list.Size() == 2);
	}

	SECTION("Push back push front")
	{
		List list;
		REQUIRE(list.Size() == 0);
		list.PushBack(1);
		REQUIRE(list.Size() == 1);
		list.PushFront(2);
		REQUIRE(list.Size() == 2);
	}

	SECTION("Push front push back")
	{
		List list;
		REQUIRE(list.Size() == 0);
		list.PushFront(1);
		REQUIRE(list.Size() == 1);
		list.PushBack(2);
		REQUIRE(list.Size() == 2);
	}

	SECTION("Push back many times")
	{
		List list;
		REQUIRE(list.Size() == 0);
		for (auto i = 1; i <= 10; ++i)
		{
			list.PushFront(i);
			REQUIRE(list.Size() == i);
		}
	}
}
