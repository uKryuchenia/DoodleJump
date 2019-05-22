#include <iostream>

#include <SFML/Graphics.hpp>
#include <Board.h>
#include <GameController.h>

using namespace std;

int main()
{
    srand (time(NULL));

    Board b;
    GameController gc(b);

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(603, 1072), "Doodle Jump");

    // Start the game loop
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();

        }
        // Clear screen
        window.clear();

        b.draw(window);
        gc.draw(window);

        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}

