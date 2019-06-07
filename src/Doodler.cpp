#include "Doodler.h"

Doodler::Doodler(Board &b,Monster &m) : board(b),monst(m)
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
                and y+70<board.platformsY(i) and dirV==Down )
        {
            dirV=Up;
            jump=board.platformsY(i)- minY;
        }
    }
}
/*

void Doodler::reactionTouchMonster()
{
    if(monst.getKillMonster()) {}
    else
    {
        if(monst.getMonsterX()-60<x and monst.getMonsterX()+140>x and  monst.getMonsterY()>y-50 and monst.getMonsterY()<y+50 )
        {
            if(dirV==Down )
            {
                monst.killMonster();
                dirV=Up;
                jump=monst.getMonsterY()- minY;
            }
            else
            {
                gameOver=true;
            }

        }
    }
}

*/

void Doodler::reactionTouchMonster()
{
    if(monst.getKillMonster()==false)
    {
        if(monst.getMonsterX()-60<x and monst.getMonsterX()+140>x and  monst.getMonsterY()>y-70 and monst.getMonsterY()<y and dirV==Up )
        {
            gameOver=true;
        }

        if(monst.getMonsterX()-60<x and monst.getMonsterX()+140>x and  monst.getMonsterY()>y and monst.getMonsterY()<y+70 and dirV==Down )
        {
            monst.killMonster();
            dirV=Up;
            jump=monst.getMonsterY()- minY;
        }
    }
}


void Doodler::motion()
{
    if (dir == Left)
        doodlerLeft.setPosition(x,y);
    if (dir == Right)
        doodlerRight.setPosition(x,y);

    if(dirV==Down)
    {
        y0=0;
        if(jump<350)
        {
            board.motion(6);
            scoreG+=6;
            jump+=6;
            setScore();
            monst.motion(6);
        }
        else
        {
            y+=6;
            reactionJumpOnPlatforms();
        }
    }
    else
    {
        y-=6.5;
        y0+=6.5;
    };
    //std::cout<<monst.getMonsterX() << " - x MONSTER\n"<<monst.getMonsterY() << " - y MONSTER\n ";
    //std::cout<<x << " - x Doodler\n"<<y << " - y Doodler\n ";

    reactionTouchMonster();

    if(y0>250 )
        dirV=Down; //ograniczenie skoku do góry
    if(y>1050 )
        gameOver=true; //koniec gry
    if(y<minY)
        dirV=Down; //ograniczenie skoku do srodka

    if(scoreG>setMonster and scoreG<setMonster+10)
    {
        monst.newMonster();
        setMonster+=1250;
        std::cout<<monst.getMonsterX() << " - x\n"<<monst.getMonsterY() << " - y\n";
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
            x-=50;
            if(x<-45)
                x=567;
            doodlerLeft.setPosition(x,y);
        }

        if (event.key.code == sf::Keyboard::Right)
        {
            dir = Right;
            x+=50;
            if(x>568)
                x=-45;
            doodlerRight.setPosition(x,y);
        }

        if (event.key.code == sf::Keyboard::Space)
        {
            monst.killMonster();
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
    setMonster=1000;
    monst.killMonster();
}

void Doodler::draw(sf::RenderWindow &window)
{
    window.draw(text);
    window.draw(text1);

    if(monst.getKillMonster()==false)
        monst.draw(window);

    if(dir==Right)
        window.draw(doodlerRight);
    else
        window.draw(doodlerLeft);
}
