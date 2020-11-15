#ifndef KEYBOARD_HANDLER
#define KEYBOARD_HANDLER

#include <array>
#include <SFML/Window.hpp>

class KeyboardHandler
{
	public:
		KeyboardHandler();

		void handle(const sf::Event &event);

		bool isPressed(int keyCode) const;
		bool isReleased(int keyCode) const;

	private:
		std::array<bool, sf::Keyboard::KeyCount> m_pKeyState;
};

#endif