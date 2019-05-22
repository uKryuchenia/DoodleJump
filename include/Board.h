#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>

struct Platforms
{
    int x;
    int y;
};

class Board
{
    sf::Texture Texture1,Texture2,Texture3,Texture4;
    sf::Sprite backgroung, slab, doodlerLeft, doodlerRight;

    Platforms plat[10];



public:

    Board();
    void draw(sf::RenderWindow &window);

};

#endif // BOARD_H
