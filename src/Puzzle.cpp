//============================================================================
// Name        : Puzzle.cpp
// Author      : Lukasz Kresa
// Version     :
// Copyright   : ---
// Description : Puzzle game for Zaawansowane C++ project
//============================================================================


#include "TextTile.h"
#include "PuzzleGame.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Font.hpp>
#include <iostream>
#include <boost/shared_ptr.hpp>

int main(int argc, char* argv[]) {
	unsigned gameSize = 4;
	//std::cout << "Rozmiar gry: ";
	//std::cin >> gameSize;
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Puzzle game - Zaawansowane C++ - Lukasz Kresa");
	window.SetPosition(0, 0);
	PuzzleGame *game = new PuzzleGame(gameSize);

	sf::Image img1, img2;
	if(!img1.LoadFromFile("doge.png"))
		std::cout << "doge.png not found.\n";
	img2.Create(200, 200, sf::Color(0, 255, 0));

	sf::Sprite spr1, spr2;
	spr1.SetImage(img1);
	spr1.SetPosition(100, 100);
	spr1.Resize(400, 300);
	spr1.SetSubRect(sf::IntRect(0, 50, img1.GetWidth(), img1.GetHeight()));
	window.Draw(spr1);
	spr2.SetImage(img2);
	window.Draw(spr2);
	std::vector<boost::shared_ptr<Tile> > tiles;
	unsigned size = 60;
	unsigned space = 10;
	for(unsigned i = 0; i < gameSize; ++i)
	{
		for(unsigned j = 0; j < gameSize; ++j)
		{
			boost::shared_ptr<Tile> tile(new TextTile((i*gameSize) + j+ 1, space + j * (size + space),
					space + i * (size + space), size));
			tiles.push_back(tile);
		}
	}


	while(window.IsOpened())
	{
		sf::Event event;
		while(window.GetEvent(event))
		{
			if(event.Type == sf::Event::Closed)
				window.Close();

			if((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Escape))
				window.Close();

			if((event.Type == sf::Event::MouseButtonPressed)
					&& (event.MouseButton.Button == sf::Mouse::Left))
			{
				for(auto it = tiles.begin(); it != tiles.end(); ++it)
				{
					if((*it)->contains(event.MouseButton.X, event.MouseButton.Y))
					{
						(*it)->onClick();
					}
				}
			}
		}
		window.Clear(sf::Color(200, 0, 0));
		for(auto it = tiles.begin(); it != tiles.end(); ++it)
			(*it)->draw(window);
		window.Display();
		//window.Clear(sf::Color(200, 0, 0));
	}

	return EXIT_SUCCESS;
}
