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

        #pragma region Accessors
        std::string getName() const;
        int getDamage() const;
        sf::Sprite getSprite();
        std::vector<Projectile*> getProjectiles() const;
        sf::Clock getDelay() const;
        void resetDelay();
        #pragma endregion

        void switch_weapon(std::string name, int damage);
        void fire();
        void update(sf::Vector2f position, sf::Vector2i direction);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void show() const;
    private:
        std::string m_sName;
        int m_iDamage;

        sf::Texture m_eTexture;
        sf::Sprite m_eSprite;
        sf::Vector2f m_ePosition;
        sf::Clock m_delay;

        std::vector<Projectile*> m_vProjectiles;
};

#endif