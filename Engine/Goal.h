#pragma once
#include "Board.h"
#include "snake.h"
#include <random>
class Goal
{
public:
	Goal(std::mt19937& rng, const Board& brd, const snake& snake);
	void Respawn( std::mt19937& rng, const Board& brd, const snake& snake);
	void Draw(Board& brd)const;
	const Location& GetLoaction()const;

private:

	static constexpr Color c = Colors::Red;
	Location loc;
};
