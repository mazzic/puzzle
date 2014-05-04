//============================================================================
// Name        : PuzzleGame.h
// Author      : Lukasz Kresa
// Version     :
// Copyright   : ---
// Description : PuzzleGame class.
//============================================================================

#ifndef GAME_H_
#define GAME_H_

#include "Settings.h"
#include "Tile.h"
#include <vector>
#include <boost/shared_ptr.hpp>

/*!*****************************************************
 * \class PuzzleGame
 * \brief Class representing a PuzzleGame object.
 *******************************************************/
class PuzzleGame
{
public:
	typedef boost::shared_ptr<PuzzleGame> Ptr;
	typedef std::vector<Tile::Ptr> Tiles;
	typedef std::vector<Tiles> VTiles;

	/*!********************************************************
	 * \brief Constructor for a PuzzleGame.
	 * \param window RenderWindow object.
	 * \param settings Settings object.
	 * ********************************************************/
	PuzzleGame(sf::RenderWindow& window, Settings& settings);

	/*!********************************************************
	 * \brief Function that returns users choose whether to
	 *        restart the game or not.
	 * \return Users choose whether to restart the game or not.
	 * ********************************************************/
	bool 		toBeRestarted() const;
	virtual 	~PuzzleGame();
private:
	typedef std::vector<unsigned> TilesNumbers;

	enum GameStatus
	{
		GameStatus_Running,
		GameStatus_Ended
	};

	/*!********************************************************
	 * \brief Waits for user input whether to restart the game or quit.
	 * ********************************************************/
	void 		askForRestart();

	/*! \brief Calculates tile size basing on the resolution and game size.
	 *  \return Tile size.
	 *  */
	unsigned 	calculateTileSize();
	bool 		checkForSuccess();
	void 		createTiles();
	void 		deletingTilesAtEnd();
	void 		drawAll();
	void 		gameplay();
	const TilesNumbers getStartingTiles(unsigned gameSize);
	void 		switchTiles(Tile::Ptr tile);
	void 		tileClicked(Tile::Ptr tile);
	void 		move(sf::Key::Code code);

	Settings& 			m_settings;
	VTiles 				m_tiles;
	GameStatus 			m_status;
	sf::RenderWindow& 	m_window;
	bool 				m_toBeRestarted;
};

#endif /* GAME_H_ */
