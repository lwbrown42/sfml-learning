#include "Player.h"
#include <iostream>

Player::Player() {
	if (!m_spriteSheet.loadFromFile("link.png"))
	{
		std::cout << "CANT LOAD LINK???" << std::endl;
	}

	m_sprite.setTexture(m_spriteSheet);
	m_sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
	m_sprite.setPosition(sf::Vector2f(0, 0));
}

sf::Sprite Player::getPlayerSprite() {
	return m_sprite;
}

void Player::move(int xTiles, int yTiles)
{
	int newX = (xTiles * 16) + position.x;
	int newY = (yTiles * 16) + position.y;

	if (newX >= 0 && newX <= WINDOW_WIDTH - 16)
	{
		position.x = newX;
	}
	if (newY >= 0 && newY <= WINDOW_HEIGHT - 16)
	{
		position.y = newY;
	}

	if (xTiles < 0)
	{
		m_sprite.setTextureRect(sf::IntRect(0, 16, 16, 16));
	}
	if (xTiles > 0)
	{
		m_sprite.setTextureRect(sf::IntRect(16, 16, -16, 16));
	}
	if (yTiles < 0)
	{
		m_sprite.setTextureRect(sf::IntRect(16, 0, 16, 16));
	}
	if (yTiles > 0)
	{
		m_sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
	}
	m_sprite.setPosition(position);
}
