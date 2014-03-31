//============================================================================
// Name        : Tile.h
// Author      : Lukasz Kresa
// Version     :
// Copyright   : ---
// Description : Klasa reprezentująca kafelek.
//============================================================================

/*! \class Tile
    \brief Class representing a tile object.

    A more detailed class description.
*/

#ifndef TILE_H_
#define TILE_H_

#include <SFML/Graphics.hpp>

class Tile
{
public:
	Tile();
	virtual ~Tile(){}

	virtual void setPosition(unsigned x, unsigned y) = 0;
	virtual unsigned getNr() = 0;
	virtual void setNr(unsigned nr) = 0;
	virtual void setX(unsigned X) = 0;
	virtual void setY(unsigned Y) = 0;
	virtual void draw(sf::RenderWindow &window) = 0;
	virtual bool contains(unsigned x, unsigned y) = 0;
	virtual unsigned getX() = 0;
	virtual unsigned getY() = 0;
	virtual void onClick();
	virtual bool visible() = 0;


private:
};

#endif /* TILE_H_ */
