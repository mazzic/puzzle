//============================================================================
// Name        : Tile.cpp
// Author      : Lukasz Kresa
// Version     :
// Copyright   : ---
// Description : Klasa reprezentująca kafelek.
//============================================================================

#include "Tile.h"

Tile::Tile(unsigned nr, unsigned x, unsigned y, unsigned size) :
	m_nr(nr), m_size(size), m_x(y), m_y(y)
{
	// TODO Auto-generated constructor stub

}

void Tile::onClick()
{
}

unsigned Tile::getNr()
{
	return m_nr;
}

void Tile::setNr(unsigned nr)
{
	m_nr = nr;
}

unsigned Tile::getX()
{
	return m_x;
}

unsigned Tile::getY()
{
	return m_y;
}

bool Tile::visible()
{
	return !!m_nr;
}
