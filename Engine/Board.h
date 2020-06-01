#pragma once
#include "Location.h"
#include "Graphics.h"

class Board
{
public:
	Board(Graphics& gfx);
		void DrawCell(const Location& loc, Color c);
		int Getgridwidth() const;
		int Getgridhight() const;
		bool IsInsidedeBoard(const Location& loc)const;

private:
	static constexpr int dimension = 20;
	static constexpr int width = 25;
	static constexpr int hight = 25;
	Graphics& gfx;
};
