//============================================================================
// Name        : Tile.h
// Author      : Lukasz Kresa
// Version     :
// Copyright   : ---
// Description : Klasa reprezentująca kafelek.
//============================================================================

/*! \class Tile
    \brief Abstract class representing a tile object.
*/

#ifndef TILE_H_
#define TILE_H_

#include <boost/shared_ptr.hpp>
#include <SFML/Graphics.hpp>

class Tile
{
public:
	typedef boost::shared_ptr<Tile> Ptr;
	Tile(unsigned nr, unsigned x, unsigned y, unsigned size);
	virtual ~Tile(){}

	virtual void setPosition(unsigned x, unsigned y) = 0;
	virtual void setX(unsigned X) = 0;
	virtual void setY(unsigned Y) = 0;
	virtual void draw(sf::RenderWindow &window) = 0;
	virtual bool contains(unsigned x, unsigned y) = 0;
	virtual void onClick();

	unsigned 		getNr();
	virtual void	setNr(unsigned nr);
	unsigned 		getX();
	unsigned 		getY();

	/*!******************************************************************
	 * \brief Function that returns boolean value about visibility of tile.
	 * \return Return bool value, if the tile is visible.
	 * ******************************************************************/
	bool visible();


protected:
	unsigned m_nr;
	unsigned m_size;
	unsigned m_x;
	unsigned m_y;
};

#endif /* TILE_H_ */
