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
	typedef boost::shared_ptr<PuzzleGame> Ptr;
	typedef std::vector<boost::shared_ptr<Tile> > Tiles;
	typedef std::vector<Tiles> VTiles;

	PuzzleGame(sf::RenderWindow& window, unsigned size);
	bool toBeRestarted() const;
	virtual ~PuzzleGame();
private:
	enum GameStatus
	{
		GameStatus_Running,
		GameStatus_Ended
	};

	void createTiles();
	void gameplay();
	void drawAll();
	bool checkForSuccess();
	unsigned calculateTileSize();
	void deletingTilesAtEnd();
	std::vector<unsigned> getStartingTiles(unsigned gameSize);
	void tileClicked(boost::shared_ptr<Tile> tile);
	void switchTiles(boost::shared_ptr<Tile> tile);
	void askForRestart();

	Settings m_settings;
	VTiles m_tiles;
	GameStatus m_status;
	sf::RenderWindow& m_window;
	unsigned m_gameSize;
	bool m_toBeRestarted;
};

#endif /* GAME_H_ */
