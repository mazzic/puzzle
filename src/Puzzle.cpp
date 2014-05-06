//============================================================================
// Name        : Puzzle.cpp
// Author      : Lukasz Kresa
// Version     :
// Copyright   : ---
// Description : Puzzle game for Zaawansowane C++ project
//============================================================================


#include "PuzzleGame.h"
#include "InputParser.h"
#include <SFML/Window.hpp>
#include <boost/shared_ptr.hpp>

int main(int argc, char* argv[]) {
	std::vector<std::string> inputStrings;
	for(int i = 1; i < argc; ++i)
		inputStrings.push_back(argv[i]);
	InputParser parser(inputStrings);

	std::cout << "Width: " << parser.getWidth() << "\n";
	std::cout << "Height: " << parser.getHeight() << "\n";
	std::cout << "GameSize: " << parser.getSize() << "\n";

	return EXIT_SUCCESS;

	Settings settings(parser.getSize(), parser.getWidth(), parser.getHeight());
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
