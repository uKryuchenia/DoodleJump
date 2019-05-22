#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <Board.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>

class GameController
{
    Board & b;

    int score=0;
    sf::Font font;
    sf::Text text,text1;


public:
    GameController(Board & board);
    std::string intToString(int x);
    void setScore();


    void draw(sf::RenderWindow &window);

};

#endif // GAMECONTROLLER_H
