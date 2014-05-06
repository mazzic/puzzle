/*
 * Game.cpp
 *
 *  Created on: Mar 16, 2014
 *      Author: amr
 */

#include "PuzzleGame.h"
#include "TextTile.h"
#include <cstdlib>
#include <fstream>
#include <boost/tokenizer.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>

PuzzleGame::PuzzleGame(sf::RenderWindow& window, Settings& settings) :
		m_settings(settings),
		m_status(GameStatus_Running), m_window(window),
		m_toBeRestarted(false)
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
	unsigned gameSize = m_settings.getGameSize();
	std::vector<unsigned> tileValues = getStartingTiles(gameSize);

	// space between tiles
	unsigned space = m_settings.getSpace();
	// determining size of tile
	unsigned size = calculateTileSize();

	for(unsigned i = 0; i < gameSize; ++i)
	{
		Tiles vect;
		m_tiles.push_back(vect);
		for(unsigned j = 0; j < gameSize; ++j)
		{
			boost::shared_ptr<Tile> tile(new TextTile(tileValues[(i * gameSize) + j], space + j * (size + space),
								space + i * (size + space), size));
			m_tiles[i].push_back(tile);
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
				for(auto it = m_tiles.begin(); it != m_tiles.end(); ++it)
				{
					if(m_status == GameStatus_Running)
					{
						for(auto it2 = it->begin(); it2 != it->end(); ++it2)
							if(m_status == GameStatus_Running)
							{
								if((*it2)->contains(event.MouseButton.X, event.MouseButton.Y))
								{
									if((*it2)->visible())
										tileClicked(*it2);
								}
							}
							else break;
					}
					else break;
				}
			}
			if((event.Type == sf::Event::KeyPressed))
			{
				move(event.Key.Code);
			}


		}
		if(m_status == GameStatus_Ended)
		{
			std::cout << "Game ended.\n";
			deletingTilesAtEnd();
			askForRestart();
			return;
		}
		drawAll();
	}
}

void PuzzleGame::drawAll()
{
	m_window.Clear(m_settings.getBackgroundColor());
	for(auto it = m_tiles.begin(); it != m_tiles.end(); ++it)
	{
		for(auto it2 = it->begin(); it2 != it->end(); ++it2)
			(*it2)->draw(m_window);
	}
	m_window.Display();
}

unsigned PuzzleGame::calculateTileSize()
{
	unsigned width = m_settings.getScreenWidth();
	unsigned height = m_settings.getScreenHeight();
	unsigned space = m_settings.getSpace();
	unsigned gameSize = m_settings.getGameSize();
	unsigned lesserDimension;
	if(width > height) lesserDimension = height;
	else			   lesserDimension = width;
	return (lesserDimension - (gameSize+1) * space)/gameSize;
}

void PuzzleGame::tileClicked(Tile::Ptr tile)
{
	switchTiles(tile);
	tile->onClick();
	if(checkForSuccess())
		m_status =  GameStatus_Ended;
}

bool PuzzleGame::checkForSuccess()
{
	unsigned gameSize = m_settings.getGameSize();
	for(unsigned i = 0; i < m_tiles.size(); ++i)
	{
		for(unsigned j = 0; j < m_tiles[i].size(); ++j)
		{
			// if not the right down corner
			if((i+j) != 2*(gameSize-1))
			{
				// check if tile at specific position has a right number
				if(m_tiles[i][j]->getNr() != (i*gameSize + j + 1))
					return false;
			}
		}
	}
	return true;
}

const PuzzleGame::TilesNumbers PuzzleGame::getStartingTiles(unsigned gameSize)
{
	typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
	boost::char_separator<char> sep(" ");

	std::vector<std::string> lines;
	std::string line;
	std::ifstream file("starting_positions.txt");
	if(!file.is_open())
	{
		printf("Unable to load starting_positions.txt file.\n");
		m_window.Close();
	}
	std::vector<TilesNumbers> loadedGames;
	while ( getline (file,line) )
	{
		unsigned pos = line.find(" ");
		if(line.substr(0, pos) == std::to_string(gameSize*gameSize - 1))
		{
			TilesNumbers tileValues;
			tokenizer tokens(line, sep);
			for(tokenizer::iterator it = tokens.begin(); it != tokens.end(); ++it)
			{
				if(it != tokens.begin())
				{
					unsigned value = atoi((*it).c_str());
					tileValues.push_back(value);
				}
			}
			loadedGames.push_back(tileValues);
			std::cout << line << "\n";
		}
	}
	file.close();

	srand (time(NULL));
	int randomValue = rand() % (loadedGames.size() + 1);
	return loadedGames[0];
}

void PuzzleGame::deletingTilesAtEnd()
{
	sf::Clock timer;
	while(true)
	{
		if(m_tiles.size() == 0)
			break;
		else if(timer.GetElapsedTime() >= 0.75)
		{
			auto it = m_tiles.end();
			std::cout << "m_tiles chosen row: " << m_tiles.size() << "\n";
			m_tiles.erase(--it);
			timer.Reset();
			std::cout << "Number of rows with tiles: " << m_tiles.size() << "\n";
		}
		drawAll();
	}
}

void PuzzleGame::switchTiles(Tile::Ptr tile)
{
	unsigned clickedTileRow, clickedTileColumn;
	// determining clicked tile coordinates
	for(unsigned row = 0; row < m_tiles.size(); ++row)
	{
		for(unsigned column = 0; column < m_tiles[row].size(); ++column)
		{
			if(m_tiles[row][column]->getNr() == tile->getNr())
			{
				clickedTileRow = row;
				clickedTileColumn = column;
				printf("Clicked tile: [%u,%u]\n", column, row);
			}
		}
	}
	if(clickedTileRow != 0)
	{
		if(m_tiles[clickedTileRow - 1][clickedTileColumn]->getNr() == 0)
		{
			Tile::Ptr empty = m_tiles[clickedTileRow -1][clickedTileColumn];
			printf("Empty tile at the position [%u, %u]\n", clickedTileRow -1, clickedTileColumn);
			unsigned emptyNr = empty->getNr();
			empty->setNr(tile->getNr());
			tile->setNr(emptyNr);

		}
	}
	if(clickedTileRow != (m_tiles.size() - 1))
	{
		if(m_tiles[clickedTileRow + 1][clickedTileColumn]->getNr() == 0)
		{
			printf("Empty tile at the position [%u, %u]\n", clickedTileRow +1, clickedTileColumn);
			Tile::Ptr empty = m_tiles[clickedTileRow+1][clickedTileColumn];
			unsigned emptyNr = empty->getNr();
			empty->setNr(tile->getNr());
			tile->setNr(emptyNr);
		}
	}
	if(clickedTileColumn != 0)
	{
		if(m_tiles[clickedTileRow][clickedTileColumn - 1]->getNr() == 0)
		{
			printf("Empty tile at the position [%u, %u]\n", clickedTileRow, clickedTileColumn -1);
			Tile::Ptr empty = m_tiles[clickedTileRow][clickedTileColumn-1];
			unsigned emptyNr = empty->getNr();
			empty->setNr(tile->getNr());
			tile->setNr(emptyNr);
		}
	}
	if(clickedTileColumn != (m_tiles[clickedTileRow].size() -1))
	{
		if(m_tiles[clickedTileRow][clickedTileColumn + 1]->getNr() == 0)
		{
			printf("Empty tile at the position [%u, %u]\n", clickedTileRow, clickedTileColumn+1);
			Tile::Ptr empty = m_tiles[clickedTileRow][clickedTileColumn+1];
			unsigned emptyNr = empty->getNr();
			empty->setNr(tile->getNr());
			tile->setNr(emptyNr);
		}
	}
}

void PuzzleGame::askForRestart()
{
	sf::String text("Press R to restart game, press ESC to quit.");
	text.SetSize(40);
	text.SetX(10);
	text.SetY(m_window.GetHeight()/2);
	m_window.Draw(text);
	m_window.Display();
	sf::Event event;
	while(m_window.IsOpened())
	{
		while(m_window.GetEvent(event))
		{
			if(event.Type == sf::Event::Closed)
				m_window.Close();

			if((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Escape))
				m_window.Close();

			if((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::R))
			{
				m_toBeRestarted = true;
				return;
			}
		}
	}
}

bool PuzzleGame::toBeRestarted() const
{
	return m_toBeRestarted;
}

void PuzzleGame::move(sf::Key::Code code)
{
	for(unsigned i = 0; i < m_tiles.size(); ++i)
	{
		for(unsigned j = 0; j < m_tiles[i].size(); ++j)
		{
			if(m_tiles[i][j]->getNr() == 0)
			{
				std::cout << "Found zero.\n";
				auto zero = m_tiles[i][j];
				if(code == sf::Key::Up)
				{
					if(i < m_tiles.size() - 1)
						tileClicked(m_tiles[i+1][j]);
				}
				if(code == sf::Key::Down)
				{
					if(i > 0)
						tileClicked(m_tiles[i-1][j]);
				}
				if(code == sf::Key::Left)
				{
					if(j < m_tiles[i].size() - 1)
						tileClicked(m_tiles[i][j+1]);
				}
				if(code == sf::Key::Right)
				{
					if( j > 0)
						tileClicked(m_tiles[i][j-1]);
				}
				return;
			}
		}
	}
}
