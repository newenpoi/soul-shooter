#ifndef PROJECTILE
#define PROJECTILE

#include <SFML/Graphics.hpp>

class Projectile : public sf::Drawable, public sf::Transformable
{
	public:
		Projectile();
		Projectile(sf::Vector2f position);

		sf::Sprite getSprite() const;
		sf::Vector2f getPosition() const;

		void update();
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	private:
		sf::Texture m_texture;
		sf::Sprite m_sprite;
		sf::Vector2f m_vPosition;
		sf::Vector2f m_velocity;
};

#endif