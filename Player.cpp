#include "Player.h"

using namespace std;

Player::Player() : m_iHealth(0), m_ePosition(sf::Vector2f()), m_eDirection(sf::Vector2f())
{
	if (!m_eImage.loadFromFile("pc/nara.png"))
	{
		
	}

	m_eImage.createMaskFromColor(sf::Color(120, 195, 128));

	m_eTexture.loadFromImage(m_eImage);

	m_eSprite.setTexture(m_eTexture);
	m_eSprite.setTextureRect(sf::IntRect(32, 0, 32, 32)); // Must change with direction.
	m_eSprite.setPosition(sf::Vector2f(64, 256));
}

sf::Vector2f Player::getDirection() const
{
	return m_eDirection;
}

void Player::setDirection(sf::Vector2f direction)
{
	m_eDirection = direction;
}

void Player::move(float speed, sf::Vector2f direction)
{
	m_eSprite.setPosition(m_eSprite.getPosition() + direction);
}

void Player::update(float delta)
{
	if (m_eDirection != sf::Vector2f())
	{
		if (m_eDirection.y < 0) m_eSprite.setTextureRect(sf::IntRect(32, (32 * 3), 32, 32));
		if (m_eDirection.y > 0) m_eSprite.setTextureRect(sf::IntRect(32, (32 * 0), 32, 32));
		if (m_eDirection.x > 0) m_eSprite.setTextureRect(sf::IntRect(32, (32 * 2), 32, 32));
		if (m_eDirection.x < 0) m_eSprite.setTextureRect(sf::IntRect(32, (32 * 1), 32, 32));

		move(delta, m_eDirection);
	}
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_eSprite, states);
}

Player::~Player()
{

}
