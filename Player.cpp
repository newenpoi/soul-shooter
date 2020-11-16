#include "Player.h"

using namespace std;


Player::Player()
{

}

Player::Player(sf::Vector2f position) : m_iHealth(100), m_iSpeed(2), m_iPrevKey(0), m_bMoving(0), m_bFiring(0), m_ePosition(position), m_eWeapon(0)
{
	// Initialise le vecteur du rectangle de texture (du sprite) à celui du milieu (1 x 32) nécessaire à l'animation.
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

	m_eWeapon = new Weapon("uzi.png", 20, m_ePosition);
}

bool Player::moving() const
{
	return m_bMoving;
}

void Player::moving(bool toggle)
{
	m_bMoving = toggle;
}

void Player::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed) m_bMoving = true;
	if (event.type == sf::Event::KeyReleased) m_bMoving = false;

	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) m_bFiring = true;
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) m_bFiring = false;
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
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_bFiring = true;
	}
	else
	{
		// Idle.
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

	if (m_bFiring)
	{
		m_eWeapon->update(m_eSprite.getPosition(), m_eAnim);
	}

	// Ajustement du rectangle de la texture du personnage à afficher.
	m_eSprite.setTextureRect(sf::IntRect(m_eAnim.x * 32, m_eAnim.y * 32, 32, 32));
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_eSprite, states);

	if (m_bFiring) target.draw(m_eWeapon->getSprite(), states);
}

Player::~Player()
{
	delete m_eWeapon;
}
