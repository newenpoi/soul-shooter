#include <iostream>
#include <string>

#include "Weapon.h"

using namespace std;

Weapon::Weapon()
{
    m_sName = "Vagrant Sword";
    m_iDamage = 10;
}

Weapon::Weapon(string name, int damage, sf::Vector2f playerPosition) : m_sName(name), m_iDamage(damage), m_ePosition(playerPosition)
{
    if (!m_eTexture.loadFromFile("tiles/" + name))
    {
        
    }

    m_eSprite.setTexture(m_eTexture);
    m_eSprite.scale(sf::Vector2f(0.7, 0.7));
    m_eSprite.setColor(sf::Color(0, 0, 0, 150));
    m_eSprite.setPosition(m_ePosition.x + 12, m_ePosition.y + 18);
}

string Weapon::getName() const
{
    return m_sName;
}

int Weapon::getDamage() const
{
    return m_iDamage;
}

sf::Sprite Weapon::getSprite()
{
    return m_eSprite;
}

void Weapon::switch_weapon(string new_weapon, int damage)
{
    m_sName = new_weapon;
    m_iDamage = damage;
}

void Weapon::update(sf::Vector2f position)
{
    m_eSprite.setPosition(position.x + 12, position.y + 18);
}

void Weapon::show() const
{
    cout << "Weapon : " << m_sName << endl;
    cout << "Damage : " << m_iDamage << endl;
}