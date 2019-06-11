#ifndef DOODLER_H
#define DOODLER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <Board.h>
#include <Monster.h>
#include <CompressionSpring.h>

enum Direction  {Left, Right};
enum VerticalDirection  {directionUp,directionDown};

class Doodler
{
    Board & board;
    Monster & monst;
    CompressionSpring & spring;

    Direction dir=Left;
    VerticalDirection dirV=directionDown;
    const int minY=400;
    int setMonster=3300;
    int jump=2000;
    int x=300,y=400;
    int y0=0,y1=0;
    bool CompressionSpringB=false;
    bool gameOver=false;

    int scoreG=0;
    sf::Font font;
    sf::Text text,text1;

    sf::Texture Texture1,Texture2;
    sf::Sprite doodlerLeft, doodlerRight;

public:
    Doodler(Board &b, Monster &m, CompressionSpring &s);

    void motion();
    void reactionJumpOnPlatforms();
    void reactionTouchMonster();
    void reactionTouchMonster1();
    void reactionJumpOnCompressionSpring();
    void setScore();
    int getScore();
    std::string intToString(int x);
    void handleEvent(sf::Event &event);
    std::string score();
    bool gameOveR();
    void restart();
    void draw(sf::RenderWindow &window);
};

#endif // DOODLER_H
