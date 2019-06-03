#ifndef DOODLER_H
#define DOODLER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
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
    int y0=0;
    bool gameOver=false;

    int scoreG=0;
    sf::Font font;
    sf::Text text,text1;

    sf::Texture Texture1,Texture2;
    sf::Sprite doodlerLeft, doodlerRight;

public:
    Doodler(Board &b);

    void motion();
    void reactionJumpOnPlatforms();
    void setScore();
    std::string intToString(int x);
    void handleEvent(sf::Event &event);
    std::string score();
    bool gameOveR();
    void restart();
    void draw(sf::RenderWindow &window);
};

#endif // DOODLER_H
