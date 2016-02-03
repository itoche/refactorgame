#pragma once

#include <sstream>
#include <string>

class Game{
private:
	std::string board;
public:
	Game(const std::string &s);
	Game(const std::string &s, int position, char player);
	int move(char player);
	Game play(int i, char player);
	char winner();
};
