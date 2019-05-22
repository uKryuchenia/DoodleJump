#include "Board.h"

Board::Board()
{
    Texture1.loadFromFile("Images/background.jpg");
    backgroung.setTexture(Texture1);

    Texture2.loadFromFile("Images/plyta.png");
    slab.setTexture(Texture2);

    Texture3.loadFromFile("Images/doodlerLeft.png");
    doodlerLeft.setTexture(Texture3);
    Texture4.loadFromFile("Images/doodlerRight.png");
    doodlerRight.setTexture(Texture4);

    for(int i=0; i<10; i++)
    {
    plat[i].x=rand() % 503;
    plat[i].y=80+rand() % 982;
    }
}

void Board::draw(sf::RenderWindow &window){

    window.draw(backgroung);

    for(int i=0; i<10; i++)
    {
    slab.setPosition(plat[i].x,plat[i].y);
    window.draw(slab);
    }

    doodlerLeft.setPosition(400,500);
    window.draw(doodlerLeft);

    //doodlerRight.setPosition(300,500);
    //window.draw(doodlerRight);



}
