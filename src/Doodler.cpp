#include "Doodler.h"

Doodler::Doodler(Board &b) : board(b)
{
    Texture1.loadFromFile("Images/doodlerLeft.png");
    doodlerLeft.setTexture(Texture1);
    Texture2.loadFromFile("Images/doodlerRight.png");
    doodlerRight.setTexture(Texture2);
    doodlerRight.setPosition(x,y);
    doodlerLeft.setPosition(x,y);

    if (!font.loadFromFile("amatic-bold.ttf"))
    {
        std::cout<<"error"<<std::endl;
    }

    text.setFont(font);
    text.setString(" Score  =  " );
    text1.setFont(font);

    text.setPosition(0,5);
    text.setCharacterSize(55);
    text.setColor(sf::Color::Black);

    text1.setPosition(120,5);
    text1.setCharacterSize(55);
    text1.setColor(sf::Color::Black);


}

std::string Doodler::intToString(int x)
{
    std::stringstream ss;
    ss << x << std::endl;
    std::string newString = ss.str();
    return newString;
}

void Doodler::setScore()
{
    text1.setString(intToString(scoreG));
}

void Doodler::reactionJumpOnPlatforms()
{
    for(int i=0; i<board.getAmountPlat(); i++)
    {
        if(board.platformsX(i)+68>x and board.platformsX(i)-51<x and  y+77>board.platformsY(i)
           and y+70<board.platformsY(i) and dirV==Down ){
            dirV = Up;
            jump=board.platformsY(i)- minY;
        }
    }
}
void Doodler::motion()
{
    if (dir == Left) doodlerLeft.setPosition(x,y);
    if (dir == Right) doodlerRight.setPosition(x,y);

    if(dirV==Down) {
            y0=0;
        if(jump<350){
            board.motion(6);
            scoreG+=6;
            jump+=6;
            setScore();
        } else {
            y+=6;
            reactionJumpOnPlatforms();
        }
    }
       else{
            y-=6.5;
            y0+=6.5;
        };
    if(y0>350 ) dirV=Down; //ograniczenie skoku do góry
    if(y>1050 ) gameOver=true; //
    if(y<minY )dirV = Down; //
    if(scoreG>1000) {
        board.setAmountPlat(10);
    }
}

void Doodler::handleEvent(sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Left)
        {
            setScore();
            dir = Left;
            x-=67;
            if(x<-45)
                x=567;
            doodlerLeft.setPosition(x,y);
        }

        if (event.key.code == sf::Keyboard::Right)
        {
            dir = Right;
            x+=67;
            if(x>568)
                x=-45;
            doodlerRight.setPosition(x,y);
        }
    }
}

bool Doodler::gameOveR()
{
   return gameOver;
}

std::string Doodler::score()
{
   return intToString(scoreG);
}

void Doodler::restart()
{
    x=300,y=400;
    gameOver=false;
    scoreG=0;
}

void Doodler::draw(sf::RenderWindow &window)
{

    window.draw(text);
    window.draw(text1);

    if(dir==Right)
        window.draw(doodlerRight);
    else
        window.draw(doodlerLeft);
}
