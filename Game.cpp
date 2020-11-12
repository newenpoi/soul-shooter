#include "Game.h"

using namespace std;

Game::Game() : m_eGameWindow(sf::VideoMode(640, 480, 16), "Soul Shooter"), m_eLevel("entry.map"), m_ePlayer(0)
{
    m_eLevel.load(sf::Vector2u(32, 32));
    m_ePlayer = new Player(sf::Vector2f(64, 64));
}

void Game::render()
{
    m_eGameWindow.setFramerateLimit(60);

    sf::Clock updateClock;
    sf::Time delta;

    while (m_eGameWindow.isOpen())
    {
        sf::Event event;

        while (m_eGameWindow.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    m_eGameWindow.close();
                    break;
                case sf::Event::KeyPressed:
                    m_ePlayer->moving(true);
                    break;
                case sf::Event::KeyReleased:
                    m_ePlayer->moving(false);
                    break;
                default:
                    break;
            }
        }

        m_ePlayer->handleInput();
        // m_ePlayer.animate(updateClock);

        if (m_ePlayer->moving())
        {
            if (updateClock.getElapsedTime().asMilliseconds() >= 50)
            {
                m_ePlayer->anim.x++;

                // Si notre animation se termine (en fonction du nombre de frames).
                if (m_ePlayer->anim.x * 32 >= (32 * 3)) m_ePlayer->anim.x = 0;

                updateClock.restart();
            }
        }

        m_ePlayer->setRect(sf::IntRect(m_ePlayer->anim.x * 32, m_ePlayer->anim.y * 32, 32, 32));

        m_eGameWindow.clear(sf::Color::Black);

        m_eLevel.draw(m_eGameWindow, sf::RenderStates::Default);
        m_ePlayer->draw(m_eGameWindow, sf::RenderStates::Default);

        m_eGameWindow.display();

        // Le sleep ci-dessous est destiné aux super-processeurs (expérimental).
        // sf::sleep(sf::microseconds(1));
    }
}

Game::~Game()
{
    delete m_ePlayer;
}