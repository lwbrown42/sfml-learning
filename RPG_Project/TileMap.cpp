#include "pch.h"
#include "TileMap.h"

bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, const int* collisionTiles, unsigned int width, unsigned int height) {
	if (!m_tileset.loadFromFile(tileset))
	{
		return false;
	}

	m_collisionTiles = collisionTiles;

	m_vertexArray.setPrimitiveType(sf::PrimitiveType::Quads);
	m_vertexArray.resize(width * height * 4);

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			int tileNumber = tiles[i + j * width];

			int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
			int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

			sf::Vertex* quad = &m_vertexArray[(i + j * width) * 4];

			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);

			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
		}
	}

	return true;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	states.texture = &m_tileset;

	target.draw(m_vertexArray, states);
}
