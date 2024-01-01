#include <GL/glew.h>
#include <OpenGL/glu.h>

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "events.h"
#include "my_keyboard.h"
#include "mouse.h"
#include "window.h"
#include "objects.h"

int main() {
  int width = 800, height = 600;
  sf::RenderWindow window(sf::VideoMode(width, height), "mini-map");
  sf::Texture texture;
  if (!texture.loadFromFile("../tools/images/ninja-cat.png")){
    std::cerr << "Фото не поддерживается";
  }
  sf::Sprite sprite(texture);
  sprite.setScale(0.15f, 0.15f);
  sprite.setPosition(width / 2 - 50, height / 2 - 50);
  while (window.isOpen()) {
    sf::Event event;
    main_events(window, event, sprite, texture);
    moving_sprite(sprite);
    window.clear(sf::Color::White);
    drawWalls(window);
    window.draw(sprite);
    window.display();
  }
  return 0;
}