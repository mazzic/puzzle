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
	sf::Color getTileColor();
	sf::Color getTileHoverColor();
	sf::Color getTilePressedColor();
	unsigned getSpace();
private:
	sf::Color m_tileColor;
	sf::Color m_tileHoverColor;
	sf::Color m_tilePressedColor;
	unsigned m_space; // distance between tiles
};

#endif /* SETTINGS_H_ */
