#include <catch2/catch_test_macros.hpp>
#include <vector>
#include "list.h"

TEST_CASE("Push and pop from empty list", "[list]") {

	SECTION("Push back, pop back")
	{
		List list;
		list.PushBack(1);
		auto item = list.PopBack();
		CHECK(item == 1);
	}

	SECTION("Push back, pop front")
	{
		List list;
		list.PushBack(1);
		auto item = list.PopFront();
		CHECK(item == 1);
	}

	SECTION("Push front, pop front")
	{
		List list;
		list.PushFront(1);
		auto item = list.PopFront();
		CHECK(item == 1);
	}

	SECTION("Push front, pop back")
	{
		List list;
		list.PushFront(1);
		auto item = list.PopBack();
		CHECK(item == 1);
	}
}

void populateList(List& list, std::vector<int> values)
{
	for (auto& i : values)
	{
		list.PushBack(i);
	}
}

TEST_CASE("Push and pop from not empty list", "[list]")
{
	std::vector<int> values{ 1, 2, 3, 4, 5 };
	auto probe = 64;

	SECTION("Push back, pop back")
	{
		List list;
		populateList(list, values);
		list.PushBack(probe);
		auto item = list.PopBack();
		CHECK(item == probe);
	}

	SECTION("Push front, pop front")
	{
		List list;
		populateList(list, values);
		list.PushFront(probe);
		auto item = list.PopFront();
		CHECK(item == probe);
	}

	SECTION("Push back, pop front")
	{
		List list;
		populateList(list, values);
		list.PushBack(probe);
		auto item = list.PopFront();
		CHECK(item != probe);
	}

	SECTION("Push front, pop back")
	{
		List list;
		populateList(list, values);
		list.PushFront(probe);
		auto item = list.PopBack();
		CHECK(item != probe);
	}

	SECTION("Pop back all items")
	{
		List list;
		populateList(list, values);
		std::for_each(values.rbegin(), values.rend(), 
			[&list](auto& expected)
			{
				auto actual = list.PopBack();
				REQUIRE(actual == expected);
			});
	}

	SECTION("Pop front all items")
	{
		List list;
		populateList(list, values);
		std::for_each(values.begin(), values.end(), 
			[&list](auto& expected)
			{
				auto actual = list.PopFront();
				REQUIRE(actual == expected);
			});
	}
}

TEST_CASE("Pop from empty list", "[list]")
{
	SECTION("Pop back")
	{
		List list;
		CHECK_THROWS_AS(list.PopBack(), std::runtime_error);
	}

	SECTION("Pop front")
	{
		List list;
		CHECK_THROWS_AS(list.PopBack(), std::runtime_error);
	}
}
