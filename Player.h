#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <SFML/Graphics.hpp>

class Player : public sf::Drawable, public sf::Transformable
{
	public:
		Player();

		enum Direction { Down, Left, Right, Up };
		sf::Vector2i anim;

		bool moving() const;
		void moving(bool toggle);

		void handleInput(sf::Event event);
		void move(float delta);
		void animate(sf::Clock clock);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual ~Player();
	private:
		int m_iHealth;
		int m_iLastDirection;
		bool m_bMoving;

		bool updateFps = false;
		float fpsCount = 0;
		float switchFps = 100;
		float fpsSpeed = 500;

		sf::Image m_eImage;
		sf::Texture m_eTexture;
		sf::Sprite m_eSprite; // Utiliser Quad ?

		sf::Vector2f m_ePosition;
		sf::Vector2f m_eVelocity;
};

#endif