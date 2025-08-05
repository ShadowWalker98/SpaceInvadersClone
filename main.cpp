
#include <iostream>
#include <SFML/Graphics.hpp>

constexpr float MOVEMENT_SPEED = 10.0f;
constexpr float MOVE_LEFT = -MOVEMENT_SPEED;
constexpr float MOVE_RIGHT = MOVEMENT_SPEED;
constexpr float MOVE_UP = -MOVEMENT_SPEED;
constexpr float MOVE_DOWN = MOVEMENT_SPEED;

void renderStep(sf::RenderWindow& currentWindow, sf::Sprite& sprite) {
    currentWindow.clear();
    currentWindow.draw(sprite);
    currentWindow.display();
}

int main() {
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);
    sf::Texture texture;

    sf::Image image;
    if(!image.loadFromFile("../images/whitecircle2.png")) {
        std::cout << "Error occurred while loading image\n";
        return -1;
    }


    if(!texture.loadFromImage(image)) {
        std::cout << "Error occurred while loading image file\n";
        return -1;
    }

    sf::Sprite sprite(texture);
    sf::Vector2<float> scaleFactor(0.2f, 0.2f);
    sprite.setScale(scaleFactor);


    while (window.isOpen()) {

        while(const std::optional event = window.pollEvent()) {

            if(!event.has_value()) {
                continue;
            }
            if(event->is<sf::Event::Closed>()) {
                window.close();
            } else if(event->is<sf::Event::KeyPressed>()) {
                auto keyEvent = event->getIf<sf::Event::KeyPressed>();
                sf::FloatRect bounds = sprite.getGlobalBounds();
                sf::Vector2 movement(0.0f, 0.0f);
                if(keyEvent->code == sf::Keyboard::Key::Left) {
                    movement.x = std::max(MOVE_LEFT, -bounds.position.x);
                } else if(keyEvent->code == sf::Keyboard::Key::Right) {
                    movement.x = std::min(MOVE_RIGHT, window.getSize().x - bounds.position.x - bounds.size.x);
                } else if(keyEvent->code == sf::Keyboard::Key::Up) {
                    movement.y = std::max(MOVE_UP, -bounds.position.y);
                } else if(keyEvent->code == sf::Keyboard::Key::Down) {
                    movement.y = std::min(MOVE_DOWN, window.getSize().y - bounds.position.y - bounds.size.y);
                }

                if(movement.x != 0.0f || movement.y != 0.0f) {
                    sprite.move(movement);
                }


                if(keyEvent->code == sf::Keyboard::Key::Escape) {
                    window.close();
                }
            }
        }
        renderStep(window, sprite);
    }
}


