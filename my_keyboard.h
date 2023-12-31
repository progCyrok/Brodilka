#include <SFML/Graphics.hpp>
namespace buttons {
  sf::Event (event);
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
    return true;
  }
  return false;
}