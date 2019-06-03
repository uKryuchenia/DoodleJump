#include "Board.h"

Board::Board()
{
    Texture1.loadFromFile("Images/background.jpg");
    backgroung.setTexture(Texture1);

    Texture2.loadFromFile("Images/plyta.png");
    slab.setTexture(Texture2);

    for(int i=0; i<2; i++)
    {
        plat[i].x=rand() % 503;
        plat[i].y=80+rand() % 182;
    }
    for(int i=2; i<5; i++)
    {
        plat[i].x=rand() % 503;
        plat[i].y=280+rand() % 182;
    }
    for(int i=5; i<8; i++)
    {
        plat[i].x=rand() % 503;
        plat[i].y=480+rand() % 182;
    }
    for(int i=8; i<10; i++)
    {
        plat[i].x=rand() % 503;
        plat[i].y=680+rand() % 182;
    }

  /*
    plat[1].x=300;
    plat[1].y=900;*/
}


void Board::motion(int x)
{
    for(int i=0; i<10; i++)
    {
        plat[i].y+=x;
        if(plat[i].y>1072){
            plat[i].x=rand() % 503;
            plat[i].y=80;
        }
    }

}

void Board::draw(sf::RenderWindow &window){

    window.draw(backgroung);

    for(int i=0; i<10; i++)
    {
        slab.setPosition(plat[i].x,plat[i].y);
        window.draw(slab);
    }

}

int Board::platformsX(int x)
{
    return plat[x].x;
}

int Board::platformsY(int y)
{
    return plat[y].y;
}
