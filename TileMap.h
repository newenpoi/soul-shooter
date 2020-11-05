#ifndef DEF_TILEMAP
#define DEF_TILEMAP

#include <string>
#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable
{
	public:
	TileMap();

	bool load(const std::string& tileSet, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);

	private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::VertexArray m_eVertices;
	sf::Texture m_eTileSet;
};

#endif