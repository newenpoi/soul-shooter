#ifndef DEF_WINDOW
#define DEF_WINDOW

#include <string>

#include <SFML/Graphics.hpp>

class Window : public sf::RenderWindow
{
	public:

	Window();
	Window(sf::VideoMode mode, const std::string &title);

	private:

	int m_iWidth;
	int m_iHeight;
};

#endif