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

TextTile::TextTile(unsigned nr, unsigned x, unsigned y, unsigned size)
					: m_nr(nr), m_size(size), m_x(x), m_y(y)
{
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
	text.SetX((x + x + size)/2);
	text.SetY((y + y + size)/2);
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

void TextTile::setPosition(unsigned x, unsigned y)
{
	setX(x);
	setY(y);

}

unsigned TextTile::getX()
{
	printf("getX: %u\n", m_x);
	return m_x;
}

unsigned TextTile::getY()
{
	printf("getY: %u\n", m_y);
	return m_y;
}

unsigned TextTile::getNr()
{
	return m_nr;
}

void TextTile::draw(sf::RenderWindow &window)
{
	if(m_nr != 0)
	{
		window.Draw(m_shape);
		text.SetX((m_x + m_x + m_size)/2);
		text.SetY((m_y + m_y + m_size)/2);
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
	if(visible())
	{
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
}

bool TextTile::visible()
{
	return m_nr;
}

void TextTile::setNr(unsigned nr)
{
	m_nr = nr;
	text.SetText(std::to_string(m_nr));
}
