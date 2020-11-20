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
    if (!m_eTexture.loadFromFile("weapons/" + name))
    {
        
    }

    m_eSprite.setTexture(m_eTexture);
    m_eSprite.setColor(sf::Color(0, 0, 0, 200));
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

std::vector<Projectile*> Weapon::getProjectiles() const
{
    return m_vProjectiles;
}

sf::Clock Weapon::getDelay() const
{
    return m_delay;
}

void Weapon::resetDelay()
{
    m_delay.restart();
}

void Weapon::switch_weapon(string new_weapon, int damage)
{
    m_sName = new_weapon;
    m_iDamage = damage;
}

void Weapon::fire()
{
    m_vProjectiles.push_back(new Projectile(m_eSprite.getPosition()));
}

void Weapon::update(sf::Vector2f position, sf::Vector2i direction)
{
    m_eSprite.setPosition(position);
    m_eSprite.setTextureRect(sf::IntRect(32, direction.y * 32, 32, 32));
}

void Weapon::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_eSprite, states);
}

void Weapon::show() const
{
    cout << "Weapon : " << m_sName << endl;
    cout << "Damage : " << m_iDamage << endl;
}