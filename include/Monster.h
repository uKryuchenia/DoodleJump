#ifndef MONSTER_H
#define MONSTER_H

#include <SFML/Graphics.hpp>

class Monster
{
    sf::Texture Texture1;
    sf::Sprite monster;
    int x=0,y=0;
    bool kill=true;

public:
    Monster();
    void newMonster();
    void motion(int x);
    void killMonster();
    int getMonsterX();
    int getMonsterY();
    bool getKillMonster();
    void draw(sf::RenderWindow &window);

};

#endif // MONSTER_H
