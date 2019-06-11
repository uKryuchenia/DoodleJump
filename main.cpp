#include <iostream>

#include <SFML/Graphics.hpp>
#include <Board.h>
#include <Doodler.h>
#include <GameController.h>
#include <Monster.h>
#include <CompressionSpring.h>


using namespace std;

int main()
{
    srand (time(NULL));

    Board b;
    CompressionSpring c(b);
    Monster m;
    Doodler d(b,m,c);
    GameController gc(b,d,c);

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(603, 972), "Doodle Jump");
    window.setFramerateLimit(45);

    // Start the game loop
    while (window.isOpen())
    {
        gc.motion();
        sf::Event event;
        while (window.pollEvent(event))
        {
            gc.handleEvent(event);
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();

        }
        // Clear screen
        window.clear();

        gc.draw(window);

        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}

