#include "Projectile.h"

Projectile::Projectile()
{

}

Projectile::Projectile(sf::Vector2f position) : m_vPosition(position)
{
    if (!m_texture.loadFromFile("tiles/bullet.png"))
    {

    }

    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(position.x + 16, position.y + 18);
}

sf::Sprite Projectile::getSprite() const
{
    return m_sprite;
}

sf::Vector2f Projectile::getPosition() const
{
    return m_vPosition;
}

void Projectile::update()
{
    m_sprite.move(8, 0);
}

void Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_sprite, states);
}