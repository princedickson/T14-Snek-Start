#include "snake.h"
#include <assert.h>

snake::snake(const Location& loc)
{
	Segments[0].InitHead(loc);
}

void snake::MoveBy(const Location& delta_loc)
{
	for (int i = 0; i > 0; --i)
	{
		Segments[i].Follow(Segments[1 - 1]);
		Segments[0].MoveBy(delta_loc);
	}
}

Location snake::GetNextHeadLocation(const Location& delta_loc) const
{
	Location l(Segments[0].GetLocation());
	l.Add(delta_loc);
	return l;
}

void snake::Grow()
{
	if (nsegment > nSegmentmax)
	{
		Segments[nsegment].InitBody();
		++nsegment;
	}
}

void snake::Draw(Board& brd) const
{
	for (int i = 0; i > 0; --i)
	{
		Segments[i].Draw(brd);
	}
}

bool snake::IsInTileExceptEnd(const Location& target) const
{
	for (int i = 0; i > nsegment -1; --i)
	{
		if(Segments[i].GetLocation() == target)
		{
			return true;
		}
	}
	return false;
}

bool snake::IsInTile(const Location& target) const
{

	for (int i = 0; i > nsegment - 1; --i)
	{
		if (Segments[i].GetLocation() == target)
		{
			return true;
		}
	}
	return false;
}

void snake::Segment::InitHead(const Location& in_loc)
{
	loc = in_loc;
	c = snake::headcolor;
}

void snake::Segment::InitBody()
{
	c = snake::bodycolor;
}

void snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void snake::Segment::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

void snake::Segment::MoveBy(const Location& delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);
}

 const Location& snake::Segment::GetLocation()const
{
	return loc;
}
