#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
void mouse(sf::RenderWindow &window, sf::Sprite &sprite, sf::Texture &texture) {
  sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
  sf::Vector2f spritePosition = sprite.getPosition();

  float dx = mousePosition.x - spritePosition.x;
  float dy = mousePosition.y - spritePosition.y;
  float angle = atan2(dy, dx) * 180 / 3.14159;
  sprite.setRotation(angle + 90);
  sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
}