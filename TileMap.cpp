#include "TileMap.h"

using namespace std;

TileMap::TileMap()
{

}

bool TileMap::load(const string& tileSet, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
{
	// Chargement de la texture des tuiles.
	if (!m_eTileSet.loadFromFile(tileSet))
		return false;

	// Redimensionnement du tableau de vertex afin qu'il contienne tout le niveau.
	m_eVertices.setPrimitiveType(sf::Quads);
	m_eVertices.resize(width * height * 4);

	// On remplit le tableau de vertex avec un quad par tuile.
	for (unsigned int i = 0; i < width; ++i)
	{
		for (unsigned int j = 0; j < height; ++j)
		{
			// On récupère le numéro de tuile courant.
			int tileNumber = tiles[i + j * width];

			// On en déduit sa position dans le tileSet.
			int tu = tileNumber % (m_eTileSet.getSize().x / tileSize.x);
			int tv = tileNumber / (m_eTileSet.getSize().x / tileSize.x);

			// On en récupère un pointeur vers le quad à définir dans le tableau de vertexes.
			sf::Vertex* quad = &m_eVertices[(i + j * width) * 4];

			// On définit ses quatre coins.
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			// On définit ses quatre coordonnées de texture.
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		}
	}

	return true;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// Appliquer la transformation.
	states.transform *= getTransform();

	// Appliquer la texture du tileSet.
	states.texture = &m_eTileSet;

	target.draw(m_eVertices, states);
}