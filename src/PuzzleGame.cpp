/*
 * Game.cpp
 *
 *  Created on: Mar 16, 2014
 *      Author: amr
 */

#include "PuzzleGame.h"
#include "TextTile.h"

PuzzleGame::PuzzleGame(sf::RenderWindow& window, unsigned size) :
		m_window(window), m_gameSize(size)
{
	createTiles();
	processEvents();
}

PuzzleGame::~PuzzleGame()
{
	// TODO Auto-generated destructor stub
}

void PuzzleGame::createTiles()
{
	// space between tiles
	unsigned space = m_settings.getSpace();
	// determining size of tile
	unsigned size = calculateGameSize();

	for(unsigned i = 0; i < m_gameSize; ++i)
		for(unsigned j = 0; j < m_gameSize; ++j)
		{
			boost::shared_ptr<Tile> tile(new TextTile((i * m_gameSize) + j+ 1, space + j * (size + space),
					space + i * (size + space), size));
			m_tiles.push_back(tile);
		}
}

void PuzzleGame::processEvents()
{
	while(m_window.IsOpened())
	{
		sf::Event event;
		while(m_window.GetEvent(event))
		{
			if(event.Type == sf::Event::Closed)
				m_window.Close();

			if((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Escape))
				m_window.Close();

			if((event.Type == sf::Event::MouseButtonPressed)
					&& (event.MouseButton.Button == sf::Mouse::Left))
			{
				for(auto it = m_tiles.begin(); it != m_tiles.end(); ++it)
				{
					if((*it)->contains(event.MouseButton.X, event.MouseButton.Y))
					{
						(*it)->onClick();
					}
				}
			}
		}
		m_window.Clear(sf::Color(200, 0, 0));
		for(auto it = m_tiles.begin(); it != m_tiles.end(); ++it)
			(*it)->draw(m_window);
		m_window.Display();
	}
}

unsigned PuzzleGame::calculateGameSize()
{
	unsigned width = m_settings.getScreenWidth();
	unsigned height = m_settings.getScreenHeight();
	unsigned space = m_settings.getSpace();
	unsigned lesserDimension;
	if(width > height) lesserDimension = height;
	else			   lesserDimension = width;
	return (lesserDimension - (m_gameSize+1) * space)/m_gameSize;
}
