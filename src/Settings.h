//============================================================================
// Name        : Settings.h
// Author      : Lukasz Kresa
// Version     :
// Copyright   : ---
// Description : Settings class.
//============================================================================

#ifndef SETTINGS_H_
#define SETTINGS_H_

#include <SFML/Graphics/Color.hpp>

/*!*******************************************************************
 * \class Settings
 * \brief Settings class holds settings for a puzzle game.
 *
 *  Settings class is intended to be created before PuzzleGame object,
 *  then passed to it as an argument, while creating PuzzleGame.
 * *******************************************************************/
class Settings
{
public:

	/*!******************************************************************
	 * \brief Constructor without arguments.
	 *  Default value of gameSize is 3.
	 *	Default screen resolution is 800x600.
	 * ******************************************************************/
	Settings();

	/*!******************************************************************
	 * \brief Constructor with arguments.
	 * \param gameSize Game size as a number of tiles in one dimention of the game.
	 * \param width Screen width in pixels.
	 * \param height Screen height in pixels.
	 * ******************************************************************/
	Settings(unsigned gameSize, unsigned width, unsigned height);

	/*!******************************************************************
	 * \brief Function that returns tile color.
	 * \return Color of the tile.
	 * ******************************************************************/
	const sf::Color& getTileColor() const;

	/*!******************************************************************
	 * \brief Function that returns hovered tile color.
	 * \return Color of the hovered tile.
	 * ******************************************************************/
	const sf::Color& getTileHoverColor() const;

	/*!******************************************************************
	 * \brief Function that returns pressed tile color.
	 * \return Color of the pressed tile.
	 * ******************************************************************/
	const sf::Color& getTilePressedColor() const;

	/*!******************************************************************
	 * \brief Function that returns background color.
	 * \return Color of the background.
	 * ******************************************************************/
	const sf::Color& getBackgroundColor() const;

	/*!******************************************************************
	 * \brief Function that returns screen width.
	 * \return Width of the screen.
	 * ******************************************************************/
	unsigned getScreenWidth() const;

	/*!******************************************************************
	 * \brief Function that returns screen height.
	 * \return Height of the screen.
	 * ******************************************************************/
	unsigned getScreenHeight() const;

	/*!******************************************************************
	 * \brief Function that returns distance between tiles.
	 * \return Distance between tiles.
	 * ******************************************************************/
	unsigned getSpace() const;

	/*!******************************************************************
	 * \brief Function that returns game size, as a number of tiles in
	 *        one direction of the game tiles square.
	 * \return Game size - number of tiles in the edge.
	 * ******************************************************************/
	unsigned getGameSize() const;
private:
	sf::Color m_tileColor;
	sf::Color m_tileHoverColor;
	sf::Color m_tilePressedColor;
	sf::Color m_backgroundColor;
	unsigned m_screenWidth;
	unsigned m_screenHeight;
	unsigned m_space; // distance between tiles
	unsigned m_gameSize;
};

#endif /* SETTINGS_H_ */
