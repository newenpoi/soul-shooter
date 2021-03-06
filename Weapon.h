#ifndef DEF_WEAPON
#define DEF_WEAPON

#include <string>
#include <SFML/Graphics.hpp>

#include "Projectile.h"

class Weapon
{
    public:
        Weapon();
        Weapon(std::string name, int damage, sf::Vector2f playerPosition);

        std::string getName() const;
        int getDamage() const;
        sf::Sprite getSprite();

        void switch_weapon(std::string name, int damage);
        void fire();
        void update(sf::Vector2f position, sf::Vector2i direction);
        void show() const;
    private:
        std::string m_sName;
        int m_iDamage;

        sf::Texture m_eTexture;
        sf::Sprite m_eSprite;
        sf::Vector2f m_ePosition;

        std::vector<Projectile> projectiles;
};

#endif