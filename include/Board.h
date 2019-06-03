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
    sf::Texture Texture1,Texture2;
    sf::Sprite backgroung, slab;
    int amountPlat=10;
    Platforms plat[10];



public:

    Board();
    void motion(int x);

    int platformsX(int x);
    int platformsY(int y);
    int setAmountPlat(int x);//
    int getAmountPlat();//
    void restart();
    void draw(sf::RenderWindow &window);

};

#endif // BOARD_H
