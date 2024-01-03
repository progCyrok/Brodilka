#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "objects.h"

void view (sf::RenderWindow &window, sf::Sprite &sprite) {
  sf::Vector2f spritePosition = sprite.getPosition();
  sf::Vertex main_line[] = {
          sf::Vertex(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y)),
          sf::Vertex(sf::Vector2f(0, 0))
      };
  main_line[1].position = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
  main_line[0].color = sf::Color::Red;
  main_line[1].color = sf::Color::Red;



  const int pointCount = 1000;
  const float radius = 100.0f;
  const float centerX = sf::Mouse::getPosition(window).x;
  const float centerY = sf::Mouse::getPosition(window).y;

  for (int i = 0; i < pointCount; ++i)
  {
      float angle = (i * 180.0f / (pointCount / 2 - 1)) * 3.14f / 180.0f; // Начинаем с -90 градусов чтобы полуокружность смотрела вверх
    float x = centerX + std::cos(angle) * radius;
    float y = centerY + std::sin(angle) * radius;

    // Отрисовываем линию
    sf::Vertex other_line[] = {
        sf::Vertex(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y)),
        sf::Vertex(sf::Vector2f(x, y))
    };
    other_line[0].color = sf::Color::Blue;
    other_line[1].color = sf::Color::Blue;
    window.draw(other_line, 2, sf::Lines);

  }


  window.draw(main_line, 2, sf::Lines);

}