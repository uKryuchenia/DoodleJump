#include <iostream>

#include <SFML/Graphics.hpp>
#include <Board.h>
#include <Doodler.h>
#include <GameController.h>
#include <Monster.h>


using namespace std;

int main()
{
    srand (time(NULL));

    Board b;
    Monster m;
    Doodler d(b,m);
    GameController gc(b,d);

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(603, 1072), "Doodle Jump");
    window.setFramerateLimit(60);

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

