/*
 * Game.h
 *
 *  Created on: Mar 16, 2014
 *      Author: amr
 */

#ifndef GAME_H_
#define GAME_H_

#include "Settings.h"

class PuzzleGame
{
public:
	PuzzleGame(unsigned size);
	virtual ~PuzzleGame();
private:
	Settings m_settings;
	unsigned m_gameSize;
	void createTiles();
};

#endif /* GAME_H_ */
