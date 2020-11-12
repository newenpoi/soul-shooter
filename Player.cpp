#include "Player.h"

using namespace std;


Player::Player()
{

}

Player::Player(sf::Vector2f position) : m_iHealth(100), m_iSpeed(2), m_bMoving(0), m_ePosition(position)
{
	m_eAnim = sf::Vector2i(1, Down);

	if (!m_eImage.loadFromFile("pc/nara.png"))
	{
		
	}

	// Permet de réaliser un masque de transparence sur une couleur spécifique.
	m_eImage.createMaskFromColor(sf::Color(120, 195, 128));

	// Charger la texture depuis l'image.
	m_eTexture.loadFromImage(m_eImage);

	// Définir la texture et la position de départ.
	m_eSprite.setTexture(m_eTexture);
	m_eSprite.setPosition(position);
}

bool Player::moving() const
{
	return m_bMoving;
}

void Player::moving(bool toggle)
{
	m_bMoving = toggle;
}

void Player::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		m_eAnim.y = Up;
		m_eSprite.move(0, -m_iSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		m_eAnim.y = Left;
		m_eSprite.move(-m_iSpeed, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_eAnim.y = Down;
		m_eSprite.move(0, m_iSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_eAnim.y = Right;
		m_eSprite.move(m_iSpeed, 0);
	}
	else
	{
		// Stationnaire.
		m_eAnim.x = 1;
	}
}

void Player::animate(sf::Clock &time)
{
	if (m_bMoving)
	{
		// Si le temps écoulé de la précédente frame excède 50.
		if (time.getElapsedTime().asMilliseconds() >= 80)
		{
			m_eAnim.x++;

			// si notre animation se termine (en fonction du nombre de frames).
			if (m_eAnim.x * 32 >= (32 * 3)) m_eAnim.x = 0;

			time.restart();
		}
	}

	// Ajustement du rectangle de la texture du personnage à afficher.
	m_eSprite.setTextureRect(sf::IntRect(m_eAnim.x * 32, m_eAnim.y * 32, 32, 32));
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_eSprite, states);
}

Player::~Player()
{

}
