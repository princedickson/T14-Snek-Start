#pragma once
#include "Board.h"

class snake
{
	class Segment
	{
	public:

		void InitHead(const Location& loc);
		void InitBody();
		void Follow(const Segment& next);
		void Draw(Board& brd) const;
		void MoveBy(const Location& delta_loc);
		const Location& GetLocation()const;


	private: 
		Location loc;
		Color c;

	};

public: 
	snake( const Location& loc);
	void MoveBy(const Location& delta_loc);
	Location GetNextHeadLocation(const Location& delta_loc)const;
	void Grow();
	void Draw(Board& brd)const;
	bool IsInTileExceptEnd(const Location& target)const;
	bool IsInTile(const Location& target)const;

private:
	static constexpr  Color headcolor = Colors::Green;
	static constexpr Color bodycolor = Colors::Yellow;
	static constexpr int nSegmentmax = 100;
	Segment Segments[nSegmentmax];
	int nsegment = 1;
};
