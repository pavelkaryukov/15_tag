// 15_tag.cpp : Defines the entry point for the application.
//
#include <iostream>
#include <SFML/Graphics.hpp>
//#include "15_tag.h"

//using namespace std;

int main()
{
    std::locale::global(std::locale(""));
    sf::RenderWindow window(sf::VideoMode(600, 600), "Пятнашки");
    window.setFramerateLimit(60);

    sf::Event event;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::KeyPressed) {
                // Получаем нажатую клавишу - выполняем соответствующее действие
                if (event.key.code == sf::Keyboard::Escape) window.close();
            }
        }

        // Выполняем необходимые действия по отрисовке
        window.clear();
        window.display();
    }

	return 0;
}
