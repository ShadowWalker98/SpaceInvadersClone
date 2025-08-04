
#include <iostream>
#include <SFML/Graphics.hpp>
#include<unordered_map>



constexpr float MOVEMENT_SPEED = 10.0f;
constexpr float MOVE_LEFT = -MOVEMENT_SPEED;
constexpr float MOVE_RIGHT = MOVEMENT_SPEED;
constexpr float MOVE_UP = -MOVEMENT_SPEED;
constexpr float MOVE_DOWN = MOVEMENT_SPEED;

const std::unordered_map<sf::Keyboard::Key, std::string> keyNameMap = {
        {sf::Keyboard::Key::A, "A"},
        {sf::Keyboard::Key::B, "B"},
        {sf::Keyboard::Key::C, "C"},
        {sf::Keyboard::Key::D, "D"},
        {sf::Keyboard::Key::E, "E"},
        {sf::Keyboard::Key::F, "F"},
        {sf::Keyboard::Key::G, "G"},
        {sf::Keyboard::Key::H, "H"},
        {sf::Keyboard::Key::I, "I"},
        {sf::Keyboard::Key::J, "J"},
        {sf::Keyboard::Key::K, "K"},
        {sf::Keyboard::Key::L, "L"},
        {sf::Keyboard::Key::M, "M"},
        {sf::Keyboard::Key::N, "N"},
        {sf::Keyboard::Key::O, "O"},
        {sf::Keyboard::Key::P, "P"},
        {sf::Keyboard::Key::Q, "Q"},
        {sf::Keyboard::Key::R, "R"},
        {sf::Keyboard::Key::S, "S"},
        {sf::Keyboard::Key::T, "T"},
        {sf::Keyboard::Key::U, "U"},
        {sf::Keyboard::Key::V, "V"},
        {sf::Keyboard::Key::W, "W"},
        {sf::Keyboard::Key::X, "X"},
        {sf::Keyboard::Key::Y, "Y"},
        {sf::Keyboard::Key::Z, "Z"},
        {sf::Keyboard::Key::Num0, "Num0"},
        {sf::Keyboard::Key::Num1, "Num1"},
        {sf::Keyboard::Key::Num2, "Num2"},
        {sf::Keyboard::Key::Num3, "Num3"},
        {sf::Keyboard::Key::Num4, "Num4"},
        {sf::Keyboard::Key::Num5, "Num5"},
        {sf::Keyboard::Key::Num6, "Num6"},
        {sf::Keyboard::Key::Num7, "Num7"},
        {sf::Keyboard::Key::Num8, "Num8"},
        {sf::Keyboard::Key::Num9, "Num9"},
        {sf::Keyboard::Key::Escape, "Escape"},
        {sf::Keyboard::Key::LControl, "LControl"},
        {sf::Keyboard::Key::LShift, "LShift"},
        {sf::Keyboard::Key::LAlt, "LAlt"},
        {sf::Keyboard::Key::LSystem, "LSystem"},
        {sf::Keyboard::Key::RControl, "RControl"},
        {sf::Keyboard::Key::RShift, "RShift"},
        {sf::Keyboard::Key::RAlt, "RAlt"},
        {sf::Keyboard::Key::RSystem, "RSystem"},
        {sf::Keyboard::Key::Menu, "Menu"},
        {sf::Keyboard::Key::LBracket, "LBracket"},
        {sf::Keyboard::Key::RBracket, "RBracket"},
        {sf::Keyboard::Key::Semicolon, "Semicolon"},
        {sf::Keyboard::Key::Comma, "Comma"},
        {sf::Keyboard::Key::Period, "Period"},
        {sf::Keyboard::Key::Apostrophe, "Apostrophe"},
        {sf::Keyboard::Key::Slash, "Slash"},
        {sf::Keyboard::Key::Backslash, "Backslash"},
        {sf::Keyboard::Key::Equal, "Equal"},
        {sf::Keyboard::Key::Hyphen, "Hyphen"},
        {sf::Keyboard::Key::Space, "Space"},
        {sf::Keyboard::Key::Enter, "Enter"},
        {sf::Keyboard::Key::Backspace, "Backspace"},
        {sf::Keyboard::Key::Tab, "Tab"},
        {sf::Keyboard::Key::PageUp, "PageUp"},
        {sf::Keyboard::Key::PageDown, "PageDown"},
        {sf::Keyboard::Key::End, "End"},
        {sf::Keyboard::Key::Home, "Home"},
        {sf::Keyboard::Key::Insert, "Insert"},
        {sf::Keyboard::Key::Delete, "Delete"},
        {sf::Keyboard::Key::Add, "Add"},
        {sf::Keyboard::Key::Subtract, "Subtract"},
        {sf::Keyboard::Key::Multiply, "Multiply"},
        {sf::Keyboard::Key::Divide, "Divide"},
        {sf::Keyboard::Key::Left, "Left"},
        {sf::Keyboard::Key::Right, "Right"},
        {sf::Keyboard::Key::Up, "Up"},
        {sf::Keyboard::Key::Down, "Down"},
        {sf::Keyboard::Key::Numpad0, "Numpad0"},
        {sf::Keyboard::Key::Numpad1, "Numpad1"},
        {sf::Keyboard::Key::Numpad2, "Numpad2"},
        {sf::Keyboard::Key::Numpad3, "Numpad3"},
        {sf::Keyboard::Key::Numpad4, "Numpad4"},
        {sf::Keyboard::Key::Numpad5, "Numpad5"},
        {sf::Keyboard::Key::Numpad6, "Numpad6"},
        {sf::Keyboard::Key::Numpad7, "Numpad7"},
        {sf::Keyboard::Key::Numpad8, "Numpad8"},
        {sf::Keyboard::Key::Numpad9, "Numpad9"},
        {sf::Keyboard::Key::F1, "F1"},
        {sf::Keyboard::Key::F2, "F2"},
        {sf::Keyboard::Key::F3, "F3"},
        {sf::Keyboard::Key::F4, "F4"},
        {sf::Keyboard::Key::F5, "F5"},
        {sf::Keyboard::Key::F6, "F6"},
        {sf::Keyboard::Key::F7, "F7"},
        {sf::Keyboard::Key::F8, "F8"},
        {sf::Keyboard::Key::F9, "F9"},
        {sf::Keyboard::Key::F10, "F10"},
        {sf::Keyboard::Key::F11, "F11"},
        {sf::Keyboard::Key::F12, "F12"},
        {sf::Keyboard::Key::F13, "F13"},
        {sf::Keyboard::Key::F14, "F14"},
        {sf::Keyboard::Key::F15, "F15"},
        {sf::Keyboard::Key::Pause, "Pause"}
};

void renderStep(sf::RenderWindow *currentWindow, sf::Sprite *sprite) {
    (*currentWindow).clear();
    (*currentWindow).draw((*sprite));
    (*currentWindow).display();
}

int main() {
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);
    sf::Texture texture;

    sf::Image image;
    if(!image.loadFromFile("/Users/satyajitmohanty/CLionProjects/SpaceInvadersClone/images/whitecircle2.png")) {
        std::cout << "Error occurred while loading image\n";
        return -1;
    }


    if(!texture.loadFromImage(image)) {
        std::cout << "Error occurred while loading image file\n";
        return 0;
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
        renderStep(&window, &sprite);
    }
}


