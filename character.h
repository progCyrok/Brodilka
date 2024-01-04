#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "objects.h"
#include "mouse.h"



void view (sf::RenderWindow &window, sf::Sprite &sprite) {
  sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
  sf::Vector2f spritePosition = sprite.getPosition();
  float dx = mousePosition.x - spritePosition.x;
  float dy = mousePosition.y - spritePosition.y;
  float distance = std::sqrt(dx * dx + dy * dy);
  if (distance != 200.f) {
    float factor = 200.f / distance;
    dx *= factor;
    dy *= factor;
  }
  float angle = std::atan2(dy, dx);
  const int rayCount = 201;
  for (int k = 0; k < rayCount; ++k) {
    float angleOffset = (static_cast<float>(k) / static_cast<float>(rayCount - 1) - 0.5f) * 1.0f;
    float newAngle = angle + angleOffset;
    sf::Vertex ray[] ={
            sf::Vertex(sprite.getPosition()),
            sf::Vertex(sprite.getPosition() + sf::Vector2f(200.f * std::cos(newAngle), 200.f * std::sin(newAngle)))
        };
    ray[0].color = sf::Color::White;
    ray[1].color = sf::Color::White;
    window.draw(ray, 2, sf::Lines);
  }
}