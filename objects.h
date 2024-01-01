#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

int width = 800, height = 600;
std::vector<sf::RectangleShape> walls;

void createWalls() {
  walls.clear();

  walls.push_back(sf::RectangleShape(sf::Vector2f(10, height - 60)));
  walls.back().setFillColor(sf::Color::Black);
  walls.back().setPosition(30, 30);

  walls.push_back(sf::RectangleShape(sf::Vector2f(10, height - 60)));
  walls.back().setFillColor(sf::Color::Black);
  walls.back().setPosition(770, 30);

  walls.push_back(sf::RectangleShape(sf::Vector2f(width - 60, 10)));
  walls.back().setFillColor(sf::Color::Black);
  walls.back().setPosition(30, 30);

  walls.push_back(sf::RectangleShape(sf::Vector2f(width - 50, 10)));
  walls.back().setFillColor(sf::Color::Black);
  walls.back().setPosition(30, 570);
}

void drawWalls(sf::RenderWindow &window) {
  createWalls();
  for (const auto &wall : walls) {
    window.draw(wall);
  }
}