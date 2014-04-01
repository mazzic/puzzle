/*
 * SpriteTile.h
 *
 *  Created on: Mar 16, 2014
 *      Author: amr
 */

#ifndef SPRITETILE_H_
#define SPRITETILE_H_

#include "Tile.h"
#include <SFML/Graphics.hpp>

/*! \class SpriteTile
    \brief Class representing a SpriteTile object.

    SpriteTile is a tile with an image instead of a number.
    Actually NOT IMPLEMENTED, NOT USED.
*/

class SpriteTile: public Tile
{
public:
	SpriteTile();
	void setSprite(sf::Sprite);
	const sf::Sprite& getSprite();
	virtual void setPosition(unsigned x, unsigned y);
	virtual void setX(unsigned x);
	virtual void setY(unsigned y);
	virtual unsigned getX();
	virtual unsigned getY();
	virtual bool contains(unsigned x, unsigned y);
	virtual void draw(sf::RenderWindow &window);
private:
	sf::Sprite sprite;
};

#endif /* SPRITETILE_H_ */
