#include "Game.h"

using namespace std;

Game::Game() : m_eGameWindow(sf::VideoMode(640, 480, 16), "Soul Shooter"), m_eLevel("entry.map"), m_ePlayer(0)
{
    m_eLevel.load(sf::Vector2u(32, 32));
    m_ePlayer = new Player(m_eLevel.getPlayerStart());
}

void Game::run()
{
    m_eGameWindow.setFramerateLimit(60);
    
    sf::Clock updateClock;
    sf::Event event;

    while (m_eGameWindow.isOpen())
    {
        

        while (m_eGameWindow.pollEvent(event))
        {
            m_ePlayer->handleEvent(event);

            if (event.type == sf::Event::Closed) m_eGameWindow.close();
        }

        m_ePlayer->handleInput();
        m_ePlayer->update(updateClock);

        render();

        #pragma region Experimental
        // Le sleep ci-dessous est destiné aux super-processeurs (expérimental).
        // sf::sleep(sf::microseconds(1));
        #pragma endregion
    }
}

void Game::render()
{
    m_eGameWindow.clear(sf::Color::Black);

    m_eLevel.draw(m_eGameWindow, sf::RenderStates::Default);
    m_ePlayer->draw(m_eGameWindow, sf::RenderStates::Default);

    m_eGameWindow.display();
}

Game::~Game()
{
    delete m_ePlayer;
}