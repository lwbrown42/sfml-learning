// RPG_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

#include "TileMap.h"
#include "Player.h"

int WINDOW_WIDTH = 160;
int WINDOW_HEIGHT = 160;

int TILE_WIDTH = 16;
int TILE_HEIGHT = 16;

int main()
{
	Player player;

	int level[100] = {

		248, 249, 249, 249, 249, 249, 249, 249, 249, 250,
		264, 265, 265, 265, 265, 265, 265, 265, 265, 266,
		264, 265, 265, 265, 265, 265, 265, 265, 265, 266,
		264, 265, 265, 265, 265, 265, 265, 265, 265, 266,
		264, 265, 265, 265, 265, 265, 265, 265, 265, 266,
		264, 265, 265, 265, 265, 265, 265, 265, 265, 266,
		264, 265, 265, 265, 265, 265, 265, 265, 265, 266,
		264, 265, 265, 265, 265, 265, 265, 265, 265, 266,
		264, 265, 265, 265, 265, 265, 265, 265, 265, 266,
		280, 281, 281, 281, 281, 281, 281, 281, 281, 282
	};

	int collisionMap[100] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	sf::Font font;
	if (!font.loadFromFile("jack.ttf")) {
		std::cout << "Error!" << std::endl;
	}

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Testing Game");
	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);

	TileMap map;
	if (!map.load("ages-overworld.png", sf::Vector2u(16, 16), level, collisionMap, 10, 10))
	{
		std::cout << "AAAAAAAAAAAAAH" << std::endl;
	}

	sf::Time time;

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::A)
					{
						player.move(-1, 0);
					}
					if (event.key.code == sf::Keyboard::D)
					{
						player.move(1, 0);
					}
					if (event.key.code == sf::Keyboard::W)
					{
						player.move(0, -1);
					}
					if (event.key.code == sf::Keyboard::S)
					{
						player.move(0, 1);
					}
					break;

				default:
					break;
			}
		}
		window.clear();
		window.draw(map);
		window.draw(player.getPlayerSprite());
		window.display();
	}
}