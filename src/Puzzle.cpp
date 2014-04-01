//============================================================================
// Name        : Puzzle.cpp
// Author      : Lukasz Kresa
// Version     :
// Copyright   : ---
// Description : Puzzle game for Zaawansowane C++ project
//============================================================================


#include "PuzzleGame.h"
#include <SFML/Window.hpp>
#include <boost/shared_ptr.hpp>

int main(int argc, char* argv[]) {
	unsigned gameSize = 3;
	Settings settings(gameSize, 1024, 768);
	sf::RenderWindow window(sf::VideoMode(settings.getScreenWidth(),
			settings.getScreenHeight(),
			32),
			"Puzzle game - Zaawansowane C++ - Lukasz Kresa",
			sf::Style::Close | sf::Style::Fullscreen);
	window.SetPosition(0, 0);
	while(true)
	{
		PuzzleGame::Ptr game(new PuzzleGame(window, settings));
		if(!game->toBeRestarted())
			break;
	}
	return EXIT_SUCCESS;
}
