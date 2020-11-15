#ifndef DEF_WEAPON
#define DEF_WEAPON

#include <string>
#include <SFML/Graphics.hpp>

class Weapon
{
    public:
        Weapon();
        Weapon(std::string name, int damage, sf::Vector2f playerPosition);

        std::string getName() const;
        int getDamage() const;
        sf::Sprite getSprite();

        void switch_weapon(std::string name, int damage);
        void update(sf::Vector2f position);
        void show() const;
    private:
        std::string m_sName;
        int m_iDamage;

        sf::Texture m_eTexture;
        sf::Sprite m_eSprite;
        sf::Vector2f m_ePosition;
};

#endif