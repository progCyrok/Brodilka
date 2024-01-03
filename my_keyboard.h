#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

void clicks(sf::RenderWindow &window, sf::Event &event) {
    if (event.key.code == sf::Keyboard::Escape)
      window.close();
}

void moving_sprite(sf::Sprite &sprite) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    sprite.move(0, -0.1f);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    sprite.move(0, 0.1f);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    sprite.move(-0.1f, 0);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    sprite.move(0.1f, 0);
}