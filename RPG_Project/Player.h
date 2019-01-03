#pragma once
#include "pch.h"
#include "common.h"
#include "SFML\Graphics.hpp"

class Player
{
public:
	Player();

	sf::Sprite getPlayerSprite();

	void move(int tileX, int tileY);

private:

	sf::Vector2f position = { 0, 0 };

	sf::Texture m_spriteSheet;
	sf::Sprite m_sprite;
};