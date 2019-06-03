#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <Board.h>
#include <Doodler.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>

class GameController
{
    Board & board;
    Doodler & doodler;

    int score=0;
    sf::Font font;
    sf::Text text,text1;


public:
    GameController(Board & b, Doodler &d);
    std::string intToString(int x);
    void setScore();

    void handleEvent(sf::Event &event);
    void draw(sf::RenderWindow &window);

};

#endif // GAMECONTROLLER_H
