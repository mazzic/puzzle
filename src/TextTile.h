/*
 * TextTile.h
 *
 *  Created on: Mar 16, 2014
 *      Author: amr
 */

#ifndef TEXTTILE_H_
#define TEXTTILE_H_

#include "Tile.h"
#include <boost/shared_ptr.hpp>

class TextTile: public Tile
{
public:
	TextTile(unsigned nr, unsigned x, unsigned y, unsigned size, bool visible);
	unsigned getNr();
	virtual void setX(unsigned x);
	virtual void setY(unsigned y);
	virtual unsigned getX();
	virtual unsigned getY();
	virtual bool contains(unsigned x, unsigned y);
	virtual void draw(sf::RenderWindow &window);
	virtual void onClick();

private:
	unsigned m_nr;
	unsigned m_size;
	unsigned m_x;
	unsigned m_y;
	sf::Shape m_shape;
	sf::Font font;
	sf::String text;
};
#endif /* TEXTTILE_H_ */
