#include "Window.h"

using namespace std;

Window::Window() : m_iWidth(640), m_iHeight(480)
{
	
}

Window::Window(sf::VideoMode mode, const string &title) : RenderWindow(mode, title), m_iWidth(640), m_iHeight(480)
{
	
}