#ifndef MNIST_ML_CPP_SFMLFUNCS_H
#define MNIST_ML_CPP_SFMLFUNCS_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#endif //MNIST_ML_CPP_SFMLFUNCS_H



void displaySingle(const int pixels[]) {
    std::string windowTitle = "bussin";
    sf::RenderWindow window(sf::VideoMode(28 * 10, 28 * 10), windowTitle);

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event{};

        // Handle Closing
        while (window.pollEvent(event)) {
            // Exiting
            if (event.type == sf::Event::Closed)
                window.close();
            }

        // Resets and Drawing
        clock.restart();
        window.clear();

        int pixelCounter = 1;
        for (int y = 28; y > 0; y--) {
            for (int x = 0; x < 28; x++) {
                // Pixel color based off of row and column
                int pxc = pixels[pixelCounter];
                pixelCounter++;


                sf::RectangleShape pixel(sf::Vector2f(10,10));
                pixel.setFillColor(sf::Color(pxc, pxc, pxc));
                pixel.setPosition((float)x * 10, (float)y * 10);

                window.draw(pixel);
            }
        }

        window.display();
    }
}

