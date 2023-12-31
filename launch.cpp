#include <GL/glew.h>
#include <OpenGL/glu.h>

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "my_keyboard.h"

int main()
{
  int width = 800, height = 600;
  sf::RenderWindow window(sf::VideoMode(width, height), "mini-map");

  sf::RectangleShape leftWall(sf::Vector2f(10, 600));
  leftWall.setFillColor(sf::Color::Green);
  leftWall.setPosition(0, 0);

  sf::RectangleShape rightWall(sf::Vector2f(10, 600));
  rightWall.setFillColor(sf::Color::Green);
  rightWall.setPosition(790, 0);

  sf::RectangleShape topWall(sf::Vector2f(800, 10));
  topWall.setFillColor(sf::Color::Green);
  topWall.setPosition(0, 0);

  sf::RectangleShape bottomWall(sf::Vector2f(800, 10));
  bottomWall.setFillColor(sf::Color::Green);
  bottomWall.setPosition(0, 590);

  sf::Texture texture;
  if (!texture.loadFromFile("../tools/images/ikonka_map.png"))
  {
    std::cerr << "Фото не поддерживается";
  }


  sf::Sprite sprite(texture);
  sprite.setScale(0.2f, 0.2f);
  sprite.setPosition(width / 2 - 50, height /2 - 50);

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
      sprite.move(0, -0.1f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
      sprite.move(0, 0.1f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
      sprite.move(-0.1f, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
      sprite.move(0.1f, 0);

    window.clear(sf::Color::White);


    window.draw(leftWall);
    window.draw(rightWall);
    window.draw(topWall);
    window.draw(bottomWall);
    window.draw(sprite);

    window.display();
  }


  return 0;
}