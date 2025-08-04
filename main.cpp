
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
                if(keyEvent->code == sf::Keyboard::Key::Left) {
                    sf::Vector2<float> leftTransform(MOVE_LEFT, 0);
                    if(bounds.position.x + leftTransform.x < 0) {
                        leftTransform.x = 0;
                    }
                    sprite.move(leftTransform);
                } else if(keyEvent->code == sf::Keyboard::Key::Right) {
                    sf::Vector2<float> rightTransform(MOVE_RIGHT, 0);
                    if(bounds.position.x + bounds.size.x + rightTransform.x > (float) window.getSize().x) {
                        rightTransform.x = 0;
                    }
                    sprite.move(rightTransform);
                } else if(keyEvent->code == sf::Keyboard::Key::Up) {
                    sf::Vector2<float> upTransform(0, MOVE_UP);
                    if(bounds.position.y + upTransform.y < 0) {
                        upTransform.y = 0;
                    }
                    sprite.move(upTransform);
                } else if(keyEvent->code == sf::Keyboard::Key::Down) {
                    sf::Vector2<float> downTransform(0, MOVE_DOWN);
                    if(bounds.position.y + bounds.size.y + downTransform.y > (float) window.getSize().y) {
                        downTransform.y = 0;
                    }
                    sprite.move(downTransform);
                }


                if(keyEvent->code == sf::Keyboard::Key::Escape) {
                    window.close();
                }
            }
        }
        renderStep(window, sprite);
    }
}


