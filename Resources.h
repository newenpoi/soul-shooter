#ifndef DEF_RESOURCES
#define DEF_RESOURCES

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Resources
{
	public:
		static bool load();

	private:
		// Empêche l'instanciation de cette classe.
		Resources() {}
};

#endif