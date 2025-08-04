
#include <iostream>
#include <SFML/Graphics.hpp>

#define LEFTX -10
#define RIGHTX 10
#define UPY -10
#define DOWNY 10
std::string getKeyName(sf::Keyboard::Key key) {
    switch (key) {
        case sf::Keyboard::Key::A: return "A";
        case sf::Keyboard::Key::B: return "B";
        case sf::Keyboard::Key::C: return "C";
        case sf::Keyboard::Key::D: return "D";
        case sf::Keyboard::Key::E: return "E";
        case sf::Keyboard::Key::F: return "F";
        case sf::Keyboard::Key::G: return "G";
        case sf::Keyboard::Key::H: return "H";
        case sf::Keyboard::Key::I: return "I";
        case sf::Keyboard::Key::J: return "J";
        case sf::Keyboard::Key::K: return "K";
        case sf::Keyboard::Key::L: return "L";
        case sf::Keyboard::Key::M: return "M";
        case sf::Keyboard::Key::N: return "N";
        case sf::Keyboard::Key::O: return "O";
        case sf::Keyboard::Key::P: return "P";
        case sf::Keyboard::Key::Q: return "Q";
        case sf::Keyboard::Key::R: return "R";
        case sf::Keyboard::Key::S: return "S";
        case sf::Keyboard::Key::T: return "T";
        case sf::Keyboard::Key::U: return "U";
        case sf::Keyboard::Key::V: return "V";
        case sf::Keyboard::Key::W: return "W";
        case sf::Keyboard::Key::X: return "X";
        case sf::Keyboard::Key::Y: return "Y";
        case sf::Keyboard::Key::Z: return "Z";
        case sf::Keyboard::Key::Num0: return "Num0";
        case sf::Keyboard::Key::Num1: return "Num1";
        case sf::Keyboard::Key::Num2: return "Num2";
        case sf::Keyboard::Key::Num3: return "Num3";
        case sf::Keyboard::Key::Num4: return "Num4";
        case sf::Keyboard::Key::Num5: return "Num5";
        case sf::Keyboard::Key::Num6: return "Num6";
        case sf::Keyboard::Key::Num7: return "Num7";
        case sf::Keyboard::Key::Num8: return "Num8";
        case sf::Keyboard::Key::Num9: return "Num9";
        case sf::Keyboard::Key::Escape: return "Escape";
        case sf::Keyboard::Key::LControl: return "LControl";
        case sf::Keyboard::Key::LShift: return "LShift";
        case sf::Keyboard::Key::LAlt: return "LAlt";
        case sf::Keyboard::Key::LSystem: return "LSystem";
        case sf::Keyboard::Key::RControl: return "RControl";
        case sf::Keyboard::Key::RShift: return "RShift";
        case sf::Keyboard::Key::RAlt: return "RAlt";
        case sf::Keyboard::Key::RSystem: return "RSystem";
        case sf::Keyboard::Key::Menu: return "Menu";
        case sf::Keyboard::Key::LBracket: return "LBracket";
        case sf::Keyboard::Key::RBracket: return "RBracket";
        case sf::Keyboard::Key::Semicolon: return "Semicolon";
        case sf::Keyboard::Key::Comma: return "Comma";
        case sf::Keyboard::Key::Period: return "Period";
        case sf::Keyboard::Key::Apostrophe: return "Apostrophe";
        case sf::Keyboard::Key::Slash: return "Slash";
        case sf::Keyboard::Key::Backslash: return "Backslash";
        case sf::Keyboard::Key::Equal: return "Equal";
        case sf::Keyboard::Key::Hyphen: return "Hyphen";
        case sf::Keyboard::Key::Space: return "Space";
        case sf::Keyboard::Key::Enter: return "Enter";
        case sf::Keyboard::Key::Backspace: return "Backspace";
        case sf::Keyboard::Key::Tab: return "Tab";
        case sf::Keyboard::Key::PageUp: return "PageUp";
        case sf::Keyboard::Key::PageDown: return "PageDown";
        case sf::Keyboard::Key::End: return "End";
        case sf::Keyboard::Key::Home: return "Home";
        case sf::Keyboard::Key::Insert: return "Insert";
        case sf::Keyboard::Key::Delete: return "Delete";
        case sf::Keyboard::Key::Add: return "Add";
        case sf::Keyboard::Key::Subtract: return "Subtract";
        case sf::Keyboard::Key::Multiply: return "Multiply";
        case sf::Keyboard::Key::Divide: return "Divide";
        case sf::Keyboard::Key::Left: return "Left";
        case sf::Keyboard::Key::Right: return "Right";
        case sf::Keyboard::Key::Up: return "Up";
        case sf::Keyboard::Key::Down: return "Down";
        case sf::Keyboard::Key::Numpad0: return "Numpad0";
        case sf::Keyboard::Key::Numpad1: return "Numpad1";
        case sf::Keyboard::Key::Numpad2: return "Numpad2";
        case sf::Keyboard::Key::Numpad3: return "Numpad3";
        case sf::Keyboard::Key::Numpad4: return "Numpad4";
        case sf::Keyboard::Key::Numpad5: return "Numpad5";
        case sf::Keyboard::Key::Numpad6: return "Numpad6";
        case sf::Keyboard::Key::Numpad7: return "Numpad7";
        case sf::Keyboard::Key::Numpad8: return "Numpad8";
        case sf::Keyboard::Key::Numpad9: return "Numpad9";
        case sf::Keyboard::Key::F1: return "F1";
        case sf::Keyboard::Key::F2: return "F2";
        case sf::Keyboard::Key::F3: return "F3";
        case sf::Keyboard::Key::F4: return "F4";
        case sf::Keyboard::Key::F5: return "F5";
        case sf::Keyboard::Key::F6: return "F6";
        case sf::Keyboard::Key::F7: return "F7";
        case sf::Keyboard::Key::F8: return "F8";
        case sf::Keyboard::Key::F9: return "F9";
        case sf::Keyboard::Key::F10: return "F10";
        case sf::Keyboard::Key::F11: return "F11";
        case sf::Keyboard::Key::F12: return "F12";
        case sf::Keyboard::Key::F13: return "F13";
        case sf::Keyboard::Key::F14: return "F14";
        case sf::Keyboard::Key::F15: return "F15";
        case sf::Keyboard::Key::Pause: return "Pause";
        default: return "Unknown";
    }
}

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
            if(event->is<sf::Event::Closed>()) {
                window.close();
            } else if(event->is<sf::Event::KeyPressed>()) {
                auto keyEvent = event->getIf<sf::Event::KeyPressed>();
                std::cout << "Key you have pressed is: " << getKeyName(keyEvent->code) << "\n";
                sf::FloatRect bounds = sprite.getGlobalBounds();
                if(keyEvent->code == sf::Keyboard::Key::Left) {
                    sf::Vector2<float> leftTransform(LEFTX, 0);
                    if(bounds.position.x + leftTransform.x < 0) {
                        leftTransform.x = 0;
                    }
                    sprite.move(leftTransform);
                    std::cout << "Moving left\n";
                } else if(keyEvent->code == sf::Keyboard::Key::Right) {
                    sf::Vector2<float> rightTransform(RIGHTX, 0);
                    if(bounds.position.x + bounds.size.x + rightTransform.x > (float) window.getSize().x) {
                        rightTransform.x = 0;
                    }
                    sprite.move(rightTransform);
                    std::cout << "Moving right\n";
                } else if(keyEvent->code == sf::Keyboard::Key::Up) {
                    sf::Vector2<float> upTransform(0, UPY);
                    if(bounds.position.y + upTransform.y < 0) {
                        upTransform.y = 0;
                    }
                    std::cout << "Moving up\n";
                    sprite.move(upTransform);
                } else if(keyEvent->code == sf::Keyboard::Key::Down) {
                    sf::Vector2<float> downTransform(0, DOWNY);
                    if(bounds.position.y + bounds.size.y + downTransform.y > (float) window.getSize().y) {
                        downTransform.y = 0;
                    }
                    sprite.move(downTransform);
                    std::cout << "Moving down\n";
                }


                if(keyEvent->code == sf::Keyboard::Key::Escape) {
                    window.close();
                }
            }
        }
        renderStep(&window, &sprite);
    }
}


