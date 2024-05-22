#pragma once
#include "SFML/Graphics.hpp"
#include "pugixml.hpp"
#include <string>
class Circle {
private:
  std::string color;
  double r;

public:
  double x;
  double y;
  std::string label;
  sf::Vector2f position() const;
  float rayon() const;
  sf::Color couleur() const;
  [[nodiscard]] std::string dump(std::string const &indent = "") const;
  Circle(const pugi::xml_node &node);
  sf::CircleShape circle2cercle();
};
