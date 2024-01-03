#include <GL/glew.h>
#include <OpenGL/glu.h>

#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "events.h"
#include "my_keyboard.h"
#include "mouse.h"
#include "window.h"
#include "objects.h"
#include "character.h"


int main() {
  int width = 800, height = 600;
  sf::RenderWindow window(sf::VideoMode(width, height), "mini-map");


  sf::Texture texture;
  if (!texture.loadFromFile("../tools/images/ninja-cat.png")){
    std::cerr << "Фото не поддерживается";
  }
  sf::Sprite sprite(texture);
  sprite.setScale(0.09f, 0.09f);
  sprite.setPosition(width / 2 - 50, height / 2 - 50);
  while (window.isOpen()) {
    sf::Event event;
    main_events(window, event, sprite, texture);
    moving_sprite(sprite);
    window.clear(sf::Color::White);
    drawing(window, sprite);
    window.draw(sprite);
    view(window, sprite);
//    const float radius = 200.0f;
//    sf::CircleShape visibilityRadius(radius);
//    visibilityRadius.setFillColor(sf::Color::Transparent);
//    visibilityRadius.setOutlineColor(sf::Color::Green);
//    visibilityRadius.setOutlineThickness(2);
//    visibilityRadius.setPosition(sprite.getPosition().x - radius, sprite.getPosition().y - radius);
//    window.draw(visibilityRadius);


    window.display();
  }
  return 0;
}