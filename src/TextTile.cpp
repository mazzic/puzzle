/*
 * TextTile.cpp
 *
 *  Created on: Mar 16, 2014
 *      Author: amr
 */

#include "TextTile.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <iostream>
#include <string>

TextTile::TextTile(unsigned nr, unsigned x, unsigned y, unsigned size, bool visible)
					: m_nr(nr), m_size(size), m_x(x), m_y(y)
{
	setVisibility(visible);
	m_shape = sf::Shape::Rectangle(x, y, x + size, y + size, sf::Color(0, 0, 255), 2);
	m_x = x;
	m_y = y;
	m_size = size;
	std::cout << x << " " << y << "\n";

	if(!font.LoadFromFile("Consolas.ttf", 24))
	{
		std::cout << "Font file not found.\n";
	}
	text.SetText(std::to_string(m_nr));
	text.SetSize(18);
	text.SetFont(font);
	text.Move((x + x + size)/2, (y + y + size)/2);
}

void TextTile::setX(unsigned x)
{
	m_shape.SetX(x);
	m_x = x;
}

void TextTile::setY(unsigned y)
{
	m_shape.SetY(y);
	m_y = y;
}

unsigned TextTile::getX()
{
	return m_x;
}

unsigned TextTile::getY()
{
	return m_y;
}

unsigned TextTile::getNr()
{
	return m_nr;
}

void TextTile::draw(sf::RenderWindow &window)
{
	if(getVisibility())
	{
		window.Draw(m_shape);
		window.Draw(text);
	}
}

bool TextTile::contains(unsigned x, unsigned y)
{
	if((x >= m_x) && (x < (m_x + m_size)))
		if((y >= m_y) && (y < (m_y + m_size)))
			return true;
	return false;
}

void TextTile::onClick()
{
	static bool clicked = false;
	if(clicked == false)
	{
		m_shape.SetColor(sf::Color(200, 0, 150));
		clicked = true;
	}
	else
	{
		m_shape.SetColor(sf::Color(0, 0, 255));
		clicked = false;
	}
}
