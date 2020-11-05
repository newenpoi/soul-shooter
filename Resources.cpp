#include "Resources.h"

using namespace std;

bool Resources::load()
{
	sf::Texture texture;

	if (!texture.loadFromFile("resources/tiles.png", sf::IntRect(32, 0, 32, 32))) cout << "Impossible de charger la ressource demandée." << endl;

	return false;
}