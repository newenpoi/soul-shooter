#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Weapon.h"

class Player : public sf::Drawable, public sf::Transformable
{
	public:
		// Constructeur.
		Player();

		// Constructeur avec Position de Départ.
		Player(sf::Vector2f position);

		enum Direction { Down, Left, Right, Up };

		#pragma region Accessors
		// None.
		#pragma endregion

		void handleEvent(const sf::Event& event);
		void handleInput();
		void animate(sf::Clock &time);
		void update(sf::Clock& time);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual ~Player();
	private:
		int m_iHealth;
		int m_iSpeed;

		bool m_bMoving;
		bool m_bFiring;

		sf::Image m_eImage;
		sf::Texture m_eTexture;
		sf::Sprite m_eSprite;

		sf::Vector2i m_eAnim;
		sf::Vector2f m_ePosition;

		Weapon *m_eWeapon;
};

#endif