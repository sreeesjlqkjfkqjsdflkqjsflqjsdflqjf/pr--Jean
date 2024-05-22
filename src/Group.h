#pragma once
#include "Circle.h"
#include "SFML/Graphics.hpp"
#include "pugixml.hpp"
#include <string>
#include <vector>
class Group {
  std::string label;

public:
  double x;
  double y;
  std::vector<Circle> children;
  std::vector<Group> enfant_groupe;
  [[nodiscard]] std::string dump(std::string const &indent = "") const;
  // Group(const pugi::xml_node &node);
  Group(const pugi::xml_node &node, double x, double y);
  void affiche(sf::RenderWindow &fenêtre) const;
  sf::Vector2f position() const;
};
