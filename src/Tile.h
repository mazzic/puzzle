//============================================================================
// Name        : Tile.h
// Author      : Lukasz Kresa
// Version     :
// Copyright   : ---
// Description : Klasa reprezentująca kafelek.
//============================================================================

#ifndef TILE_H_
#define TILE_H_

#include <SFML/Graphics.hpp>

class Tile
{
public:
	Tile();
	virtual ~Tile(){}

	void setPosition(unsigned x, unsigned y);
	virtual void setX(unsigned X) = 0;
	virtual void setY(unsigned Y) = 0;
	virtual void draw(sf::RenderWindow &window) = 0;
	virtual bool contains(unsigned x, unsigned y) = 0;
	virtual unsigned getX() = 0;
	virtual unsigned getY() = 0;
	virtual void onClick();
	bool getVisibility();
	void setVisibility(bool v);

private:
	bool m_visible;
};

#endif /* TILE_H_ */
