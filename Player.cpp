#include "Player.h"

using namespace std;

Player::Player() : m_iHealth(100), m_iLastDirection(0), m_bMoving(false), m_iCurrFrame(0), m_iLastFrame(0), frameMove(0), m_ePosition(sf::Vector2f(0, 0))
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

void Player::handleInput(sf::Event event)
{
	// Type d'évènement sur touche appuyée.
	if (event.type == sf::Event::KeyPressed && !m_bMoving)
	{
		// On bloque la direction (évite les déplacements en diagonale).
		m_bMoving = true;

		// On enregistre la dernière direction dans laquelle on se déplace.
		m_iLastDirection = event.key.code;

		// Ajuster la vélocité.
		switch (event.key.code)
		{
			case sf::Keyboard::Z:
				m_eVelocity -= sf::Vector2f(0, 32);
				break;
			case sf::Keyboard::Q:
				m_eVelocity -= sf::Vector2f(32, 0);
				break;
			case sf::Keyboard::S:
				m_eVelocity += sf::Vector2f(0, 32);
				break;
			case sf::Keyboard::D:
				m_eVelocity += sf::Vector2f(32, 0);
				break;
		}
	}

	// Type d'évènement sur touche relachée.
	if (event.type == sf::Event::KeyReleased)
	{
		// La touche relâchée correspond à la dernière direction.
		if (event.key.code == m_iLastDirection)
		{
			// Ajuster la vélocité.
			switch (event.key.code)
			{
				case sf::Keyboard::Z:
					m_eVelocity += sf::Vector2f(0, 32);
					break;
				case sf::Keyboard::Q:
					m_eVelocity += sf::Vector2f(32, 0);
					break;
				case sf::Keyboard::S:
					m_eVelocity -= sf::Vector2f(0, 32);
					break;
				case sf::Keyboard::D:
					m_eVelocity -= sf::Vector2f(32, 0);
					break;
			}

			m_bMoving = false;
		}
	}
}

void Player::move(float delta)
{
	// Gauche ou Droite.
	m_ePosition.x += m_eVelocity.x * (delta / 1000.f);

	// Haut ou Bas.
	m_ePosition.y += m_eVelocity.y * (delta / 1000.f);

	// It's show time.
	m_eSprite.setPosition(m_ePosition);
}

void Player::animate()
{
	if (frameMove)
		m_iLastFrame += 500 * updateClock.restart().asSeconds();
	else
		m_iLastFrame = 0;

	if (m_iLastFrame > 100)
	{
		m_iCurrFrame++;
		if (m_iCurrFrame == 2) m_iCurrFrame = 0;
	}

	if (m_eVelocity.y < 0) m_eSprite.setTextureRect(sf::IntRect(32 * m_iCurrFrame, 32 * 3, 32, 32));
	if (m_eVelocity.y > 0) m_eSprite.setTextureRect(sf::IntRect(32 * m_iCurrFrame, 32 * 0, 32, 32));
	if (m_eVelocity.x > 0) m_eSprite.setTextureRect(sf::IntRect(32 * m_iCurrFrame, 32 * 2, 32, 32));
	if (m_eVelocity.x < 0) m_eSprite.setTextureRect(sf::IntRect(32 * m_iCurrFrame, 32 * 1, 32, 32));
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_eSprite, states);
}

Player::~Player()
{

}
