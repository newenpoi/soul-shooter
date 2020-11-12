#ifndef DEF_GAME
#define DEF_GAME

#include <iostream>
#include <unordered_map>
#include <SFML/Graphics.hpp>

#include "Window.h"
#include "KeyboardHandler.h"
#include "Level.h"

class Game
{
	public:
		Game();
		~Game();
		void render();
	private:
		Window m_eGameWindow;
		Level m_eLevel;
		Player *m_ePlayer;
};

#endif