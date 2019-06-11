#include "GameController.h"

GameController::GameController(Board & b, Doodler &d, CompressionSpring & s) : board(b), doodler(d),spring(s)
{

    Texture1.loadFromFile("Images/backgroundEnd.jpg");
    backgroung.setTexture(Texture1);
    Texture2.loadFromFile("Images/restart.png");
    restart.setTexture(Texture2);
    restart.setPosition(230,600);
    Texture3.loadFromFile("Images/exit.png");
    exit.setTexture(Texture3);
    exit.setPosition(230,750);

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

    text2.setFont(font);
    text2.setString(" Game Over " );
    text2.setPosition(30,300);
    text2.setCharacterSize(195);
    text2.setColor(sf::Color::Black);
}

void GameController::newSpring()
{
    int scoreForSpring=2000+rand()%1300;//pojawianie sie sprezyny w roznych czasach

    if(doodler.getScore()>scoreForSpring*s1) s=1;

    if(s)
    {
        spring.newSpring();
        s=0;
        s1++;
    }
}

void GameController::motion()
{
    if(doodler.gameOveR()==false){
        doodler.motion();
        newSpring();
    }

}
void GameController::handleEvent(sf::Event &event)
{
    int x=0,y=0;
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            x=event.mouseButton.x;
            y=event.mouseButton.y;
        }
    }

    if(x<400 and x>230 and y>600 and y<660) //przycisk restart
    {
        doodler.restart();
        board.restart();
        spring.restart();
        s1=1;
    }
    if(x<400 and x>230 and y>750 and y<810)
        ex=1; //przycisk koniec

    doodler.handleEvent(event);
}

void GameController::draw(sf::RenderWindow &window)
{
    if(doodler.gameOveR()==false)
    {
        board.draw(window);
        spring.draw(window);
        doodler.draw(window);
    }
    else
    {
        text1.setString(doodler.score());
        window.draw(backgroung);
        window.draw(text);
        window.draw(text1);
        window.draw(text2);
        window.draw(restart);
        window.draw(exit);
    }
    if(ex)
        window.close();
}

