#include "GameController.h"

GameController::GameController(Board & board) : b(board)
{

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

std::string GameController::intToString(int x)
{
    std::stringstream ss;
    ss << x << std::endl;
    std::string newString = ss.str();
    return newString;
}

void GameController::setScore()
{
    text1.setString(intToString(score));
}

void GameController::draw(sf::RenderWindow &window){
    setScore();
    window.draw(text);
    window.draw(text1);

}
