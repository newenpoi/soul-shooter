#ifndef PROJECTILE
#define PROJECTILE

#include <SFML/System.hpp>

class Projectile
{
public:
	Projectile();
private:
	sf::Vector2f velocity;
};

#endif