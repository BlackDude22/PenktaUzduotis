#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "wordMap.h"
#include <string>

TEST_CASE("Test 1", "[single-file]"){
	word_map map;
	std::ifstream inf;
	inf.open("input.txt");
	map.readFromStream(inf);
	REQUIRE(map.getCount("a") == 104);
	REQUIRE(map.getCount("small") == 5);
	REQUIRE(map.getCount("other") == 17);
	REQUIRE(*map.getSet("a").begin() == 27);
}
