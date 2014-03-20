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
	gameplay();
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
	{
		Tiles vect;
		m_ptiles.push_back(vect);
		for(unsigned j = 0; j < m_gameSize; ++j)
		{
			boost::shared_ptr<Tile> tile(new TextTile((i * m_gameSize) + j, space + j * (size + space),
					space + i * (size + space), size));
			m_ptiles[i].push_back(tile);
		}
	}
}

void PuzzleGame::gameplay()
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
				for(auto it = m_ptiles.begin(); it != m_ptiles.end(); ++it)
				{
					for(auto it2 = it->begin(); it2 != it->end(); ++it2)
						if((*it2)->contains(event.MouseButton.X, event.MouseButton.Y))
						{
							if((*it2)->visible())
								tileClicked(*it2);
						}

							//(*it2)->onClick();
				}
			}
		}
		drawAll();
	}
}

void PuzzleGame::drawAll()
{
	m_window.Clear(m_settings.getBackgroundColor());
	for(auto it = m_ptiles.begin(); it != m_ptiles.end(); ++it)
	{
		for(auto it2 = it->begin(); it2 != it->end(); ++it2)
			(*it2)->draw(m_window);
	}
	m_window.Display();
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

void PuzzleGame::tileClicked(boost::shared_ptr<Tile> tile)
{
	switchTiles(tile);
	tile->onClick();
}

void PuzzleGame::switchTiles(boost::shared_ptr<Tile> tile)
{
	unsigned clickedTileRow, clickedTileColumn;
	// determining clicked tile coordinates
	for(unsigned row = 0; row < m_ptiles.size(); ++row)
	{
		for(unsigned column = 0; column < m_ptiles[row].size(); ++column)
		{
			if(m_ptiles[row][column]->getNr() == tile->getNr())
			{
				clickedTileRow = row;
				clickedTileColumn = column;
				printf("Clicked tile: [%u,%u]\n", column, row);
			}
		}
	}
	if(clickedTileRow != 0)
	{
		if(m_ptiles[clickedTileRow - 1][clickedTileColumn]->getNr() == 0)
		{
			boost::shared_ptr<Tile> empty = m_ptiles[clickedTileRow -1][clickedTileColumn];
			printf("Empty tile at the position [%u, %u]\n", clickedTileRow -1, clickedTileColumn);
			//unsigned emptyTileX = empty->getX();
			//printf("X = %u\n", emptyTileX);
			//unsigned emptyTileY = empty->getY();
			//printf("Y = %u\n", emptyTileY);
			//empty->setPosition(tile->getX(), tile->getY());
			//tile->setPosition(emptyTileX, emptyTileY);
			//printf("X = %u\n", tile->getX());
			//printf("Y = %u\n", tile->getY());
			unsigned emptyNr = empty->getNr();
			empty->setNr(tile->getNr());
			tile->setNr(emptyNr);

		}
	}
	if(clickedTileRow != (m_ptiles.size() - 1))
	{
		if(m_ptiles[clickedTileRow + 1][clickedTileColumn]->getNr() == 0)
		{
			printf("Empty tile at the position [%u, %u]\n", clickedTileRow +1, clickedTileColumn);
			boost::shared_ptr<Tile> empty = m_ptiles[clickedTileRow+1][clickedTileColumn];
			unsigned emptyNr = empty->getNr();
			empty->setNr(tile->getNr());
			tile->setNr(emptyNr);
		}
	}
	if(clickedTileColumn != 0)
	{
		if(m_ptiles[clickedTileRow][clickedTileColumn - 1]->getNr() == 0)
		{
			printf("Empty tile at the position [%u, %u]\n", clickedTileRow, clickedTileColumn -1);
			boost::shared_ptr<Tile> empty = m_ptiles[clickedTileRow][clickedTileColumn-1];
			unsigned emptyNr = empty->getNr();
			empty->setNr(tile->getNr());
			tile->setNr(emptyNr);
		}
	}
	if(clickedTileColumn != (m_ptiles[clickedTileRow].size() -1))
	{
		if(m_ptiles[clickedTileRow][clickedTileColumn + 1]->getNr() == 0)
		{
			printf("Empty tile at the position [%u, %u]\n", clickedTileRow, clickedTileColumn+1);
			boost::shared_ptr<Tile> empty = m_ptiles[clickedTileRow][clickedTileColumn+1];
			unsigned emptyNr = empty->getNr();
			empty->setNr(tile->getNr());
			tile->setNr(emptyNr);
		}
	}
}
