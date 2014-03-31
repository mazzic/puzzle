/*
 * Settings.cpp
 *
 *  Created on: Mar 16, 2014
 *      Author: amr
 */

#include "Settings.h"

Settings::Settings() :
		m_tileColor(sf::Color(0, 0, 255)),
		m_tileHoverColor(sf::Color(220, 0, 170)),
		m_tilePressedColor(sf::Color(200, 0, 150)),
		m_backgroundColor(sf::Color(200, 0, 0)),
		m_screenWidth(800),
		m_screenHeight(600),
		m_space(30),
		m_gameSize(3)
{

}

Settings::Settings(unsigned gameSize, unsigned width, unsigned height) :
		m_tileColor(sf::Color(0, 0, 255)),
		m_tileHoverColor(sf::Color(220, 0, 170)),
		m_tilePressedColor(sf::Color(200, 0, 150)),
		m_backgroundColor(sf::Color(200, 0, 0)),
		m_screenWidth(width),
		m_screenHeight(height),
		m_space(30),
		m_gameSize(gameSize)
{

}

sf::Color Settings::getTileColor() const
{
	return m_tileColor;
}

sf::Color Settings::getTileHoverColor() const
{
	return m_tileHoverColor;
}

sf::Color Settings::getTilePressedColor() const
{
	return m_tilePressedColor;
}

sf::Color Settings::getBackgroundColor() const
{
	return m_backgroundColor;
}

unsigned Settings::getSpace() const
{
	return m_space;
}

unsigned Settings::getScreenWidth() const
{
	return m_screenWidth;
}

unsigned Settings::getScreenHeight() const
{
	return m_screenHeight;
}

unsigned Settings::getGameSize() const
{
	return m_gameSize;
}
