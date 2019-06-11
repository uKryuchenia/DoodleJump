#include "CompressionSpring.h"

CompressionSpring::CompressionSpring(Board &b) : board(b)
{
    Texture1.loadFromFile("Images/Spring.png");
    compressionSpring.setTexture(Texture1);
}

void CompressionSpring::newSpring()
{
    platforms=board.getResetPlat();

    z=1;
    x=board.platformsX(platforms)+10+rand()%60;
    y=board.platformsY(platforms)-16;  //na przyklad 7-wysokosc spring
}

void CompressionSpring::motion(int xy)
{
    y+=xy;
}

int CompressionSpring::getSpringX()
{
    return x;
}

int CompressionSpring::getSpringY()
{
    return y;
}


void CompressionSpring::restart()
{
    z=0;
}

void CompressionSpring::draw(sf::RenderWindow &window)
{
    if(z){
    compressionSpring.setPosition(x,y);
    window.draw(compressionSpring);
    }
}
