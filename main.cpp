#include <iostream>

#include <SFML/Graphics.hpp>
#include <Board.h>
#include <Doodler.h>
#include <GameController.h>


using namespace std;

int main()
{
    srand (time(NULL));

    Board b;
    Doodler d(b);
    GameController gc(b,d);

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(603, 1072), "Doodle Jump");
    window.setFramerateLimit(30);

    // Start the game loop
    while (window.isOpen())
    {
        d.motion();
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

        b.draw(window);
        d.draw(window);
        gc.draw(window);

        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}

