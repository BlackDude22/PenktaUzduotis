#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>
#include "catch.hpp"
#include "wordMap.h"

int main(int argc, char const *argv[])
{
	word_map map;
	std::ifstream inf;
	inf.open("input.txt");
	map.readFromStream(inf);
	map.printMap(5);
	system("pause");
}