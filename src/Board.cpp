#include "Board.h"

Board::Board()
{
    Texture1.loadFromFile("Images/background.jpg");
    backgroung.setTexture(Texture1);

    Texture2.loadFromFile("Images/plyta.png");
    slab.setTexture(Texture2);

    plat[0].x=300;
    plat[0].y=800+(rand() % 30);

    for(int i=1,j=80; i<amountPlat; i++,j+=85)
    {
        plat[i].x=rand() % 503;
        plat[i].y=j+(rand() % 30);
    }
}


void Board::motion(int x)
{
    for(int i=0; i<amountPlat; i++)
    {
        plat[i].y+=x;
        if(plat[i].y>1072)
        {
            plat[i].x=rand() % 503;
            plat[i].y=100;
            resetPlat=i;
        }
    }
}

void Board::restart()
{
    plat[0].x=300;
    plat[0].y=900+(rand() % 30);

    for(int i=1,j=80; i<amountPlat; i++,j+=85)
    {
        plat[i].x=rand() % 503;
        plat[i].y=j+(rand() % 30);
    }
}

void Board::draw(sf::RenderWindow &window)
{
    window.draw(backgroung);

    for(int i=0; i<amountPlat; i++)
    {
        slab.setPosition(plat[i].x,plat[i].y);
        window.draw(slab);
    }
}

int Board::setAmountPlat(int x)
{
    amountPlat=x;
}

int Board::getResetPlat()
{
    return resetPlat;
}

int Board::getAmountPlat()
{
    return amountPlat;
}

int Board::platformsX(int x)
{
    return plat[x].x;
}

int Board::platformsY(int y)
{
    return plat[y].y;
}
