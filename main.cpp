#include <iostream>
#include <SFML/Graphics.hpp>
#include "my_keyboard.h"

int main() {
  // Создаем окно размером 800x600
  sf::RenderWindow window(sf::VideoMode(800, 600), "Practic");

  // Основной цикл программы
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      if (close_window_esc(event)) {
        window.close();
      }
    }

    // Очищаем окно (заливаем фон чёрным)
    window.clear(sf::Color::White);

    // Создаем шар с радиусом 50
    sf::CircleShape circle(50.f);

    // Устанавливаем цвет шара на зеленый
    circle.setFillColor(sf::Color::Green);

    // Устанавливаем позицию шара в центр окна
    circle.setPosition(800 / 2 - 50, 600 / 2 - 50);

    // Рисуем шар
    window.draw(circle);

    // Отображаем содержимое окна
    window.display();
  }

  return 0;
}
