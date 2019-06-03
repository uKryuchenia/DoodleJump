#include "Doodler.h"

Doodler::Doodler(Board &b) : board(b)
{
    Texture1.loadFromFile("Images/doodlerLeft.png");
    doodlerLeft.setTexture(Texture1);
    Texture2.loadFromFile("Images/doodlerRight.png");
    doodlerRight.setTexture(Texture2);
    doodlerRight.setPosition(x,y);
    doodlerLeft.setPosition(x,y);
}

void Doodler::motion()
{
    if (dir == Left) doodlerLeft.setPosition(x,y);
    if (dir == Right) doodlerRight.setPosition(x,y);

    if(dirV==Down) {
        if(jump<350){
            board.motion(6);
            jump+=6;
        } else y+=6;
    }
       else{
            y-=6.5;
        }

    if(y>1072 ) gameOver=true;

    if(y<minY )
    {
        dirV = Down;
    }

    for(int i=0; i<10; i++)
    {
        if(board.platformsX(i)+68>x and board.platformsX(i)-51<x and  y+77>board.platformsY(i) and y+70<board.platformsY(i) and dirV==Down  ){

            std:: cout<< board.platformsY(i) << " - y\n";
            jump=board.platformsY(i)- minY;
            dirV = Up;

        }
    }
}

void Doodler::handleEvent(sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Left)
        {
            dir = Left;
            x-=37;
            if(x<-45)
                x=567;
            doodlerLeft.setPosition(x,y);
        }

        if (event.key.code == sf::Keyboard::Right)
        {
            dir = Right;
            x+=37;
            if(x>568)
                x=-45;
            doodlerRight.setPosition(x,y);
        }
    }
}

void Doodler::draw(sf::RenderWindow &window)
{
    if(dir==Right)
        window.draw(doodlerRight);
    else
        window.draw(doodlerLeft);
}
