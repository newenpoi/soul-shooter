#include "Level.h"

using namespace std;

Level::Level() : m_iWidth(0), m_iHeight(0), m_strTileSet("default.png")
{

}

Level::Level(const string& name)
{
    int width, height;
    string tile, content;

    // ios::in ou input operations.
    ifstream f("maps/" + name, ios::in);

    if (!f.is_open())
    {
        cout << "Le fichier n'a pu etre ouvert." << endl;
        exit(1);
    }

    // Attention le type doit corresponde au contenu du fichier.
    while (f >> width >> height >> tile >> content >> m_ePlayerStart.x >> m_ePlayerStart.y)
    {

    }

    f.close();

    m_strTileSet = tile;
    m_iWidth = width;
    m_iHeight = height;

    m_eTiles = Helper::stringToVector((width * height), content);
}

sf::Vector2f Level::getPlayerStart()
{
    return m_ePlayerStart;
}

bool Level::load(sf::Vector2u size)
{
    if (!m_eTexture.loadFromFile("tiles/" + m_strTileSet)) return false;

    // On a besoin du type de primitives et dans notre cas il s'agit de quads.
    m_eVertices.setPrimitiveType(sf::Quads);

    // Setsumei suru tanomu.
    m_eVertices.resize(m_iWidth * m_iHeight * 4);

    // On remplit notre tableau de vertexes avec un quad par tuile.
    for (unsigned int i = 0; i < m_iWidth; ++i)
    {
        for (unsigned int j = 0; j < m_iHeight; ++j)
        {
            int tile = m_eTiles[i + j * m_iWidth];

            // On en déduit sa position dans le tile set (U et V dénotent l'axe de la texture 2D).
            int tu = tile % (m_eTexture.getSize().x / size.x);
            int tv = tile / (m_eTexture.getSize().x / size.x);

            // On créé un pointeur vers le quad à définir dans le tableau de vertex.
            sf::Vertex* quad = &m_eVertices[(i + j * m_iWidth) * 4];

            // On définit ses coins (simple maths).
            quad[0].position = sf::Vector2f(i * size.x, j * size.y);
            quad[1].position = sf::Vector2f((i + 1) * size.x, j * size.y);
            quad[2].position = sf::Vector2f((i + 1) * size.x, (j + 1) * size.y);
            quad[3].position = sf::Vector2f(i * size.x, (j + 1) * size.y);

            // On définit ses coordonnées de texture (simple maths).
            quad[0].texCoords = sf::Vector2f(tu * size.x, tv * size.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * size.x, tv * size.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * size.x, (tv + 1) * size.y);
            quad[3].texCoords = sf::Vector2f(tu * size.x, (tv + 1) * size.y);
        }
    }

    return true;
}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    states.texture = &m_eTexture;

    target.draw(m_eVertices, states);
}
