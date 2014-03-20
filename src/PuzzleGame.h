/*
 * Game.h
 *
 *  Created on: Mar 16, 2014
 *      Author: amr
 */

#ifndef GAME_H_
#define GAME_H_

#include "Settings.h"
#include "Tile.h"
#include <vector>
#include <boost/shared_ptr.hpp>

class PuzzleGame
{
public:
	typedef std::vector<boost::shared_ptr<Tile> > Tiles;
	typedef std::vector<std::vector<boost::shared_ptr<Tile> > > PTiles;

	PuzzleGame(sf::RenderWindow& window, unsigned size);
	virtual ~PuzzleGame();
private:
	Settings m_settings;
	Tiles m_tiles;
	PTiles m_ptiles;
	sf::RenderWindow& m_window;
	unsigned m_gameSize;
	void createTiles();
	void processEvents();
	void drawAll();
	unsigned calculateGameSize();
};

#endif /* GAME_H_ */
