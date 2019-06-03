#ifndef DOODLER_H
#define DOODLER_H

#include <iostream>
#include <Board.h>

enum Direction  {Left, Right};
enum VerticalDirection  {Up, Down};

class Doodler
{
    Board & board;
    Direction dir=Left;
    VerticalDirection dirV=Down;
    const int minY=400;
    int jump=1000;
    int x=300,y=400;
    bool gameOver=false;

    sf::Texture Texture1,Texture2;
    sf::Sprite doodlerLeft, doodlerRight;

public:
    Doodler(Board &b);

    void motion();
    void handleEvent(sf::Event &event);

    void draw(sf::RenderWindow &window);
};

#endif // DOODLER_H
