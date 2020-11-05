#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <SFML/Graphics.hpp>

class Player : public sf::Drawable, public sf::Transformable
{
	public:
		Player();
		void move(float speed, int direction);
		void move(float speed, sf::Vector2f direction);

		enum Directions {NORTH = -1, SOUTH = 1, EAST, WEST};

		bool isMoving();
		void isMoving(bool moving);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual ~Player();
	private:
		int m_iHealth;

		bool m_bIsMoving;

		sf::Image m_eImage;
		sf::Texture m_eTexture;
		sf::Sprite m_eSprite; // Utiliser Quad ?
		sf::Vector2f m_ePosition;
};

#endif