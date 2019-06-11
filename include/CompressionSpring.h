#ifndef COMPRESSIONSPRING_H
#define COMPRESSIONSPRING_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Board.h>
#include <iostream>


class CompressionSpring
{
    Board & board;

    sf::Texture Texture1;
    sf::Sprite compressionSpring;
    int x=0,y=0;
    int z=0; //ta zmienna odpowiada temu, że jak jest =0, sprężyna nie będzie wyświetlana, kiedy będzie =1, będzie wyświetlana
    int platforms=0;

public:
    CompressionSpring(Board &b);
    void newSpring();
    void motion(int xy);
    int getSpringX();
    int getSpringY();
    void restart();
    void draw(sf::RenderWindow &window);

};

#endif // COMPRESSIONSPRING_H
