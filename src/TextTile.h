//============================================================================
// Name        : TextTile.h
// Author      : Lukasz Kresa
// Version     :
// Copyright   : ---
// Description : TextTile class.
//============================================================================

#ifndef TEXTTILE_H_
#define TEXTTILE_H_

#include "Tile.h"
#include <boost/shared_ptr.hpp>

/*!*******************************************************************
 * \class TextTile
 * \brief Class representing a TextTile object. Implements Tile interface.
 * *******************************************************************/
class TextTile: public Tile
{
public:
	/*!*******************************************************************
	 * \brief Constructor for a text tile.
	 * \param nr Number that identifies the tile.
	 * \param x Position of the tile in the horizontal direction [pixels].
	 * \param y Position of the tile in the vertical direction [pixels].
	 * \param size Size of the tile.
	 * *******************************************************************/
	TextTile(unsigned nr, unsigned x, unsigned y, unsigned size);

	/*!*******************************************************************
	 * \brief Function returns number that identifies the tile.
	 * \return Number that identifies the tile.
	 * ******************************************************************/
	virtual unsigned 	getNr();

	/*!******************************************************************
	 * \brief Function that sets numbers identifying the tile.
	 * \param nr Number that identifies the tile.
	 * ******************************************************************/
	virtual void 		setNr(unsigned nr);

	/*!******************************************************************
	 * \brief Function that sets horizontal position of tile.
	 * \param x Position of the tile in the horizontal direction [pixels].
	 * ******************************************************************/
	virtual void 		setX(unsigned x);

	/*!******************************************************************
	 * \brief Function that sets vertical position of tile.
	 * \param y Position of the tile in the vertical direction [pixels].
	 * ******************************************************************/
	virtual void 		setY(unsigned y);

	/*!******************************************************************
	 * \brief Function that sets position of tile.
	 * \param x Position of the tile in the horizontal direction [pixels].
	 * \param y Position of the tile in the vertical direction [pixels].
	 * ******************************************************************/
	virtual void 		setPosition(unsigned x, unsigned y);

	/*!******************************************************************
	 * \brief Function returning horizontal position of tile.
	 * \return y Position of the tile in the horizontal direction [pixels].
	 * ******************************************************************/
	virtual unsigned 	getX();

	/*!******************************************************************
	 * \brief Function returning vertical position of tile.
	 * \return y Position of the tile in the vertical direction [pixels].
	 * ******************************************************************/
	virtual unsigned 	getY();

	/*!******************************************************************
	 * \brief Function that checks, if mouse click with coordinates x,y
	 * 		  is in the range of the tile.
	 * \param x Position of the mouse click in the horizontal direction [pixels].
	 * \param y Position of the mouse click in the vertical direction [pixels].
	 * \return Bool value that tells if point[x,y] is in the tile.
	 * ******************************************************************/
	virtual bool contains(unsigned x, unsigned y);

	/*!******************************************************************
	 * \brief Function that draws the tile on the window.
	 * \param window RenderWindow object on which tile is presented.
	 * ******************************************************************/
	virtual void draw(sf::RenderWindow &window);

	/*!******************************************************************
	 * \brief Function lauched when tile is clicked. Handles tile color changing.
	 * ******************************************************************/
	virtual void onClick();

	/*!******************************************************************
	 * \brief Function that returns boolean value about visibility of tile.
	 * \return Return bool value, if the tile is visible.
	 * ******************************************************************/
	virtual bool visible();

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
