#include "Player.h"

using namespace std;


Player::Player()
{

}

Player::Player(sf::Vector2f position) : m_iHealth(100), m_iSpeed(2), m_bMoving(0), m_ePosition(position)
{
	anim = sf::Vector2i(1, Down);

	if (!m_eImage.loadFromFile("pc/nara.png"))
	{
		
	}

	m_eImage.createMaskFromColor(sf::Color(120, 195, 128));

	m_eTexture.loadFromImage(m_eImage);

	m_eSprite.setTexture(m_eTexture);
	m_eSprite.setTextureRect(sf::IntRect(32, 0, 32, 32)); // Must change with direction.
	m_eSprite.setPosition(sf::Vector2f(64, 256));
}

bool Player::moving() const
{
	return m_bMoving;
}

void Player::moving(bool toggle)
{
	m_bMoving = toggle;
}

sf::Sprite Player::getSprite()
{
	return m_eSprite;
}

void Player::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		anim.y = Up;
		m_eSprite.move(0, -2);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		anim.y = Left;
		m_eSprite.move(-2, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		anim.y = Down;
		m_eSprite.move(0, 2);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		anim.y = Right;
		m_eSprite.move(2, 0);
	}
}

void Player::setRect(sf::IntRect rectangle)
{
	m_eSprite.setTextureRect(rectangle);
}

void Player::animate(sf::Clock &time)
{
	if (m_bMoving)
	{
		if (time.getElapsedTime().asMilliseconds() >= 50)
		{
			anim.x--;

			// si notre animation se termine (en fonction du nombre de frames).
			if (anim.x * 32 >= (32 * 3)) anim.x = 2;

			time.restart();
		}
	}

	m_eSprite.setTextureRect(sf::IntRect(anim.x * 32, anim.y * 32, 32, 32));
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_eSprite, states);
}

Player::~Player()
{

}
