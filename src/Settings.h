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

/*! \class Settings
    \brief Settings class holds settings for a puzzle game.

    Settings class is intended to be created before PuzzleGame object,
    then passed to it as an argument, while creating PuzzleGame.
*/

class Settings
{
public:

	/*! \brief Constructor without arguments.
		Default value of gameSize is 3.
		Default screen resolution is 800x600.
	 */
	Settings();
	/*! \brief Constructor with arguments.
	 *  \param gameSize Game size as a number of tiles in one dimention of the game.
	 *  \param width Screen width in pixels.
	 *  \param height Screen height in pixels.
	 */
	Settings(unsigned gameSize, unsigned width, unsigned height);
	/*! \return Color of the tile. */
	sf::Color getTileColor() const;

	/*! \return Color of the hovered tile. */
	sf::Color getTileHoverColor() const;

	/*! \return Color of the pressed tile. */
	sf::Color getTilePressedColor() const;

	/*! \return Color of the background. */
	sf::Color getBackgroundColor() const;

	/*! \return Width of the screen. */
	unsigned getScreenWidth() const;

	/*! \return Height of the screen. */
	unsigned getScreenHeight() const;

	/*! \return Distance between tiles. */
	unsigned getSpace() const;

	/*! \return Game size - number of tiles in the edge. */
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
