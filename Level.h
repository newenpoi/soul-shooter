#ifndef LEVEL
#define LEVEL

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Helper.h"

class Level : public sf::Drawable, public sf::Transformable
{
	public:
		Level();
		Level(const std::string& name);

		sf::Vector2f getPlayerStart();

		bool load(sf::Vector2u tileSize);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	private:
		unsigned int m_iWidth;
		unsigned int m_iHeight;

		std::string m_strTileSet;

		sf::Texture m_eTexture;
		sf::VertexArray m_eVertices;
		std::vector<int> m_eTiles;

		sf::Vector2f m_ePlayerStart;
};

#endif