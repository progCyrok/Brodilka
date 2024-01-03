#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "my_keyboard.h"
#include "mouse.h"

void main_events(sf::RenderWindow &window, sf::Event &event, sf::Sprite &sprite, sf::Texture &texture) {
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::KeyPressed) {
      clicks(window, event);
    }
    if (event.type == sf::Event::Closed) {
      window.close();
    }
    if (event.type == sf::Event::MouseMoved) {
      mouse(window, sprite, texture);
    }
  }
}