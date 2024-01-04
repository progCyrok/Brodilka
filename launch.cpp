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

  sf::Texture floorTexture;
  if (!floorTexture.loadFromFile("/Users/rinatkamalov/CLionProjects/opengl_game/tools/images/grey_fon.jpeg"))
  {
    std::cerr << "Фото не поддерживается";
  }
  sf::Sprite floorSprite(floorTexture);

  sprite.setScale(0.09f, 0.09f);
  sprite.setPosition(width / 2 - 50, height / 2 - 50);
  while (window.isOpen()) {
    sf::Event event;
    main_events(window, event, sprite, texture);
    moving_sprite(sprite);
    window.clear();
    window.draw(floorSprite);
    drawing(window, sprite);
    window.draw(sprite);
    view(window, sprite);
    const float radius = 30.0f;

    window.display();
  }
  return 0;
}