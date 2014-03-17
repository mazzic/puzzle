/*
 * Settings.h
 *
 *  Created on: Mar 16, 2014
 *      Author: amr
 */

#ifndef SETTINGS_H_
#define SETTINGS_H_

#include <SFML/Graphics/Color.hpp>

class Settings
{
public:
	Settings();
	sf::Color getTileColor() const;
	sf::Color getTileHoverColor() const;
	sf::Color getTilePressedColor() const;
	sf::Color getBackgroundColor() const;
	unsigned getScreenWidth() const;
	unsigned getScreenHeight() const;
	unsigned getSpace() const;
private:
	sf::Color m_tileColor;
	sf::Color m_tileHoverColor;
	sf::Color m_tilePressedColor;
	sf::Color m_backgroundColor;
	unsigned m_screenWidth;
	unsigned m_screenHeight;
	unsigned m_space; // distance between tiles
};

#endif /* SETTINGS_H_ */
