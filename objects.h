#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

int width = 800, height = 600;
std::vector<sf::RectangleShape> walls;


std::vector<sf::RectangleShape> cubs;

void createWalls(sf::Sprite &sprite) {
  walls.clear();

  walls.push_back(sf::RectangleShape(sf::Vector2f(10, height - 60)));
  walls.back().setFillColor(sf::Color::Black);
  walls.back().setPosition(30, 30);
  if (sprite.getGlobalBounds().intersects(walls[0].getGlobalBounds())) {
    sprite.move(1.0, 0.0f);
  }

  walls.push_back(sf::RectangleShape(sf::Vector2f(10, height - 60)));
  walls.back().setFillColor(sf::Color::Black);
  walls.back().setPosition(770, 30);
  if (sprite.getGlobalBounds().intersects(walls[1].getGlobalBounds())) {
    sprite.move(-1.0, 0.0f);
  }

  walls.push_back(sf::RectangleShape(sf::Vector2f(width - 60, 10)));
  walls.back().setFillColor(sf::Color::Black);
  walls.back().setPosition(30, 30);
  if (sprite.getGlobalBounds().intersects(walls[2].getGlobalBounds())) {
    sprite.move(0.0, 1.0f);
  }

  walls.push_back(sf::RectangleShape(sf::Vector2f(width - 50, 10)));
  walls.back().setFillColor(sf::Color::Black);
  walls.back().setPosition(30, 570);
  if (sprite.getGlobalBounds().intersects(walls[3].getGlobalBounds())) {
    sprite.move(0.0, -1.0f);
  }
}

void createCubs (sf::Sprite sprite) {
  if (cubs.size() == 0) {
    int numCubes = rand() % 5 + 1;;
    for (int i = 0; i < numCubes; ++i) {
      int x = std::rand() % 700, y = std::rand() % 500;
      int size_ = std::rand() % 70;
      cubs.push_back(sf::RectangleShape(sf::Vector2f(70, 70)));
      cubs.back().setFillColor(sf::Color::Black);
      cubs.back().setPosition(x, y);
    }
  }
}


void drawing(sf::RenderWindow &window, sf::Sprite &sprite) {
  createWalls(sprite);
  for (const auto &wall : walls) {
    window.draw(wall);
  }
  createCubs(sprite);
  for (const auto &cube : cubs) {
    sf::Vector2f cubePosition = cube.getPosition();
    sf::Vector2f spritePosition = sprite.getPosition();
    if (sprite.getGlobalBounds().intersects(cube.getGlobalBounds())) {
      if (spritePosition.x < cubePosition.x) {
        sprite.move(-1, 0);
      }
      if (spritePosition.x > cubePosition.x) {
        sprite.move(1, 0);
      }
      if (spritePosition.y < cubePosition.y) {
        sprite.move(0, -1);
      }
      if (spritePosition.y > cubePosition.y) {
        sprite.move(0, 1);
      }
    }
    window.draw(cube);
  }
}