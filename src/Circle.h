#pragma once
#include "pugixml.hpp"
#include <string>
class Circle {
  std::string label;
  double x;
  double y;
  double r;
  std::string color;

public:
  [[nodiscard]] std::string dump(std::string const &indent = "") const;
  Circle(const pugi::xml_node &node);
};
