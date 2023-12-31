#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Fast & Furious");
    window.setFramerateLimit(60);

    sf::CircleShape circle(30);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(0, 300);

    float initialVelocity = 2.0f;
    float finalVelocity = 8.0f;
    float velocityIncrement = 1.0f;

    float currentVelocity = initialVelocity;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        circle.move(currentVelocity, 0);

        if (circle.getPosition().x > window.getSize().x) {

            circle.setPosition(0, 300);

            if (currentVelocity < finalVelocity) {
                currentVelocity += velocityIncrement;
            }
        }

        window.clear();

        window.draw(circle);

        window.display();
    }

    return 0;
}
