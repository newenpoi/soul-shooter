#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <SFML/Graphics.hpp>

class Player : public sf::Drawable, public sf::Transformable
{
	public:
		// Constructeur.
		Player();
		// Constructeur avec Position de Départ.
		Player(sf::Vector2f position);

		enum Direction { Down, Left, Right, Up };

		bool moving() const;
		void moving(bool toggle);

		void handleInput();
		void animate(sf::Clock &time);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual ~Player();
	private:
		int m_iHealth;
		int m_iSpeed;

		bool m_bMoving;

		sf::Image m_eImage;
		sf::Texture m_eTexture;
		sf::Sprite m_eSprite; // Utiliser Quad ?

		sf::Vector2i m_eAnim;
		sf::Vector2f m_ePosition;
		sf::Vector2f m_eVelocity;
};

#endif