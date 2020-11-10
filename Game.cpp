#include "Game.h"

using namespace std;

Game::Game() : m_eGameWindow(sf::VideoMode(640, 480, 16), "Soul Shooter"), m_eLevel("entry.map")
{
    m_eLevel.load(sf::Vector2u(32, 32));
}

void Game::render()
{
    m_eGameWindow.setFramerateLimit(60);

    sf::Clock updateClock;
    sf::Time delta;

    m_eGameWindow.setKeyRepeatEnabled(false);

    while (m_eGameWindow.isOpen())
    {
        sf::Event event;

        while (m_eGameWindow.pollEvent(event))
        {
            m_ePlayer.handleInput(event);

            switch (event.type)
            {
                case sf::Event::Closed:
                    m_eGameWindow.close();
                    break;
                default:
                    break;
            }
        }

        m_ePlayer.move(delta.asMilliseconds());

        delta = updateClock.restart();

        m_eGameWindow.clear(sf::Color::Black);

        m_eLevel.draw(m_eGameWindow, sf::RenderStates::Default);
        m_ePlayer.draw(m_eGameWindow, sf::RenderStates::Default);

        m_eGameWindow.display();

        // Le sleep ci-dessous est destiné aux super-processeurs (expérimental).
        // sf::sleep(sf::microseconds(1));
    }
}