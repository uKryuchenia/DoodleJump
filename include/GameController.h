#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <Board.h>
#include <Doodler.h>

class GameController
{
    Board & board;
    Doodler & doodler;
    sf::Texture Texture1,Texture2,Texture3;
    sf::Sprite backgroung,restart,exit;
    sf::Font font;
    sf::Text text,text1,text2;

    int ex=0; //zamkniecie okna

public:

    GameController(Board & b, Doodler &d);
    void motion();
    void handleEvent(sf::Event &event);
    void draw(sf::RenderWindow &window);

};

#endif // GAMECONTROLLER_H
