#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <SFML/Graphics.hpp>

class Player : public sf::Drawable, public sf::Transformable
{
	public:
		Player();

		sf::Vector2f getDirection() const;
		void setDirection(sf::Vector2f direction);

		void move(float speed, sf::Vector2f direction);
		void update(float delta);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual ~Player();
	private:
		int m_iHealth;

		sf::Image m_eImage;
		sf::Texture m_eTexture;
		sf::Sprite m_eSprite; // Utiliser Quad ?
		sf::Vector2f m_ePosition;
		sf::Vector2f m_eDirection;
};

#endif