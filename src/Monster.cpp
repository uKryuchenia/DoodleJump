#include "Monster.h"

Monster::Monster()
{
    Texture1.loadFromFile("Images/monster.png");
    monster.setTexture(Texture1);
}

void Monster::newMonster()
{
    x=rand()%403;
    y=100;
    kill=false;
}

void Monster::motion(int x)
{
    y+=x;
    if(y>1072)
        kill=true;
}

void Monster::killMonster()
{
    kill=true;
}

int Monster::getMonsterX()
{
    return x;
}

int Monster::getMonsterY()
{
    return y;
}

bool Monster::getKillMonster()
{
    return kill;
}

void Monster::draw(sf::RenderWindow &window)
{
    if(kill) {}
    else
    {
        monster.setPosition(x,y);
        window.draw(monster);
    }
}
