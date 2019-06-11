#include "Doodler.h"

Doodler::Doodler(Board &b, Monster &m, CompressionSpring & s) : board(b),monst(m),spring(s)
{
    Texture1.loadFromFile("Images/doodlerLeft1.png");
    doodlerLeft.setTexture(Texture1);
    Texture2.loadFromFile("Images/doodlerRight1.png");
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
        if(board.platformsX(i)+68>x and board.platformsX(i)-68<x and  y+77>board.platformsY(i)
                and y+70<board.platformsY(i) and dirV==directionDown )
        {
            dirV=directionUp;
            jump=board.platformsY(i)- minY;
        }
    }
}

void Doodler::reactionJumpOnCompressionSpring()
{
    for(int i=0; i<board.getAmountPlat(); i++)
    {
        if(spring.getSpringX()>x and spring.getSpringX()-80<x and  y<spring.getSpringY()
                and y+70>spring.getSpringY() and dirV==directionDown )
        {
            dirV=directionUp;
            jump=board.platformsY(i)- minY;
            CompressionSpringB=true;
        }
    }
}

void Doodler::reactionTouchMonster1()
{
    if(monst.getKillMonster()==false)
    {
        if(monst.getMonsterX()-60<x and monst.getMonsterX()+160>x and  monst.getMonsterY()>y-80 and monst.getMonsterY()<y-60)
        {
            gameOver=true;
        }
    }
}

void Doodler::reactionTouchMonster()
{
    if(monst.getKillMonster()==false)
    {
        if(monst.getMonsterX()-60<x and monst.getMonsterX()+160>x and  monst.getMonsterY()>y-80
           and monst.getMonsterY()<y-60 and dirV == directionUp)
        {
            gameOver=true;
        }
        if(monst.getMonsterX()-60<x and monst.getMonsterX()+160>x and  monst.getMonsterY()>y
           and monst.getMonsterY()<y+70 and dirV == directionDown)
        {
            monst.killMonster();
            dirV=directionUp;
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

    reactionTouchMonster();

    if(dirV==directionDown)
    {
        y0=0;y1=0;
        if(jump<1150 and CompressionSpringB==true){
            board.motion(10);
            scoreG+=10;
            jump+=10;
            setScore();
            monst.motion(10);
            spring.motion(10);
        }
        else if(jump<350)
        {
            board.motion(6);
            scoreG+=6;
            jump+=6;
            setScore();
            monst.motion(6);
            spring.motion(6);
        }
        else
        {
            y+=6;
            reactionJumpOnCompressionSpring();
            reactionJumpOnPlatforms();
        }
    }
    else if(dirV==directionUp)
    {
        y-=6.5;
        y0+=6.5;
        y1+=6.5;
    }

    if(jump>700)
        CompressionSpringB=false;

    if(y0>250 )
        dirV=directionDown; //ograniczenie skoku do góry z dolnych platform
    if(y>900 )
        gameOver=true; //koniec gry

    if(y<minY){
        dirV=directionDown; //ograniczenie skoku do srodka
        reactionTouchMonster1();
        }

    if(scoreG>setMonster and scoreG<setMonster+10)
    {
        monst.newMonster();
        setMonster+=4250;
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
            x-=35;
            if(x<-45)
                x=567;
            doodlerLeft.setPosition(x,y);
        }

        if (event.key.code == sf::Keyboard::Right)
        {
            dir = Right;
            x+=35;
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


int Doodler::getScore()
{
    return scoreG;
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
    setMonster=3300;
    monst.killMonster();
    jump=2000;
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
