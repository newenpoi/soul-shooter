#include "Game.h"

using namespace std;

Game::Game() : m_eGameWindow(sf::VideoMode(640, 480, 16), "Soul Shooter"), m_eLevel("entry.map")
{
    m_eLevel.load(sf::Vector2u(32, 32));
}

void Game::render()
{
    sf::Time updateTime;
    sf::Clock updateClock;

    m_eGameWindow.setFramerateLimit(60);

    while (m_eGameWindow.isOpen())
    {
        // ? --> m_eEvents.handle(m_eGameWindow); // Can I ?
        m_ePlayer.update(updateClock.getElapsedTime().asSeconds());

        sf::Event event;

        while (m_eGameWindow.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    m_eGameWindow.close();
                    break;
                case sf::Event::KeyPressed:
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                    {
                        m_ePlayer.m_bNorth = true;
                        // m_ePlayer.move(updateClock.getElapsedTime().asSeconds(), m_ePlayer.NORTH);
                        // m_ePlayer.move(updateClock.getElapsedTime().asSeconds(), sf::Vector2f(0, -32));
                    }
                    break;
                case sf::Event::KeyReleased:
                    if (event.key.code == sf::Keyboard::Z)
                    {
                        m_ePlayer.m_bNorth = false;
                    }
                default:
                    break;
            }
        }

        m_eGameWindow.clear(sf::Color::Black);

        m_eLevel.draw(m_eGameWindow, sf::RenderStates::Default);
        m_ePlayer.draw(m_eGameWindow, sf::RenderStates::Default);

        m_eGameWindow.display();
    }
}