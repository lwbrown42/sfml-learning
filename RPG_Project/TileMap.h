#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "common.h"

class TileMap : public sf::Drawable, sf::Transformable {
public:
	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, const int* collisionTiles, unsigned int width, unsigned int height);
private:
	sf::VertexArray m_vertexArray;
	sf::Texture m_tileset;
	
	const int *m_collisionTiles;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};