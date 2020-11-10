#include "KeyboardHandler.h"

KeyboardHandler::KeyboardHandler()
{
	m_pKeyState.fill(true);
}

void KeyboardHandler::handle(sf::Event event)
{
	m_pKeyState[event.key.code] = event.key.code;
}

bool KeyboardHandler::isPressed(int keyCode) const
{
	return (m_pKeyState[keyCode] == sf::Event::KeyPressed);
}

bool KeyboardHandler::isReleased(int keyCode) const
{
	return (m_pKeyState[keyCode] == sf::Event::KeyReleased);
}
