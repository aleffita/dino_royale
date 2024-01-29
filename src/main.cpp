#include <iostream>

#include "game.hpp"

int main() {
    ldtk::Project project;
    std::string ldtk_filename = "assets/maps/world1.ldtk";
    try {
        project.loadFromFile(ldtk_filename);
        std::cout << "LDtk World \"" << project.getFilePath() << "\" was loaded successfully." << std::endl;
    }
    catch (std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        return 1;
    }

    // initialize the game from the LDtk project data
    Game game;
    game.init(project);

    // create the window
    sf::RenderWindow window;
    window.create(sf::VideoMode(800, 500), "LDtkLoader - SFML");
    window.setFramerateLimit(60);

    // start game loop
    while(window.isOpen()) {

        // EVENTS
        sf::Event event{};
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::F1)
                    game.show_colliders = !game.show_colliders;
                else if (event.key.code == sf::Keyboard::F5) {
                    // reload the LDtk project and reinitialize the game
                    project.loadFromFile(ldtk_filename);
                    game.init(project, true);
                    std::cout << "Reloaded project " << project.getFilePath() << std::endl;
                }
                else if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
        }

        // UPDATE
        game.update();

        // RENDER
        window.clear();
        game.render(window);
        window.display();

    }
    return 0;
}
