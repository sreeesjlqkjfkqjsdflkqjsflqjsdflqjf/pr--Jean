#pragma once
#include "Circle.h"
#include "pugixml.hpp"
#include <string>
#include <vector>
class Group {
  std::string label;
  double x;
  double y;

public:
  std::vector<Circle> children;
  std::vector<Group> enfant_groupe;
  [[nodiscard]] std::string dump(std::string const &indent = "") const;
  Group(const pugi::xml_node &node);
};
