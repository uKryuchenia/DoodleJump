#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <Board.h>
#include <Doodler.h>

class GameController
{
    Board & board;
    Doodler & doodler;
    CompressionSpring & spring;

    sf::Texture Texture1,Texture2,Texture3;
    sf::Sprite backgroung,restart,exit;
    sf::Font font;
    sf::Text text,text1,text2;

    int ex=0; //zamkniecie okna gdy wartość nei jest równa 0
    int s=0; // jeśli tą zmienna jest równa 0, pojawia się nowa sprężyna
    int s1=1; // mnoznik dla score, zeby co jakiś czas pojawiała się sprężyna

public:

    GameController(Board & b, Doodler &d,  CompressionSpring &s);
    void motion();
    void newSpring();
    void handleEvent(sf::Event &event);
    void draw(sf::RenderWindow &window);

};

#endif // GAMECONTROLLER_H
