#include "Player.h"

using namespace std;

Player::Player() : m_iHealth(0)
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

bool Player::isMoving()
{
	return m_bIsMoving;
}

void Player::isMoving(bool moving)
{
	m_bIsMoving = moving;
}

void Player::move(float speed, int direction)
{
	if (direction == NORTH)
	{
		m_eSprite.setPosition(m_eSprite.getPosition() - sf::Vector2f(0, speed));
	}
}

void Player::move(float speed, sf::Vector2f direction)
{
	if (direction.y < 0) m_eSprite.setTextureRect(sf::IntRect(32, (32 * 3), 32, 32));
	m_eSprite.setPosition(m_eSprite.getPosition() - sf::Vector2f(0, speed));
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_eSprite, states);
}

Player::~Player()
{

}
