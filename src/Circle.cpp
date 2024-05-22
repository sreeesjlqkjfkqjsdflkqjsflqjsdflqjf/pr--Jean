#include "Circle.h"
#include <map>
#include <sstream>
#include <string>

using namespace std;

Circle::Circle(const pugi::xml_node &node) {
  label = node.attribute("label").as_string();
  x = node.attribute("x").as_double();
  y = node.attribute("y").as_double();
  r = node.attribute("r").as_double();
  color = node.attribute("color").as_string();
}
float Circle::rayon() const { return r; }
sf::Color Circle::couleur() const {
  std::map<std::string, sf::Color> carte{
      {"Magenta", sf::Color::Magenta},
      {"Red", sf::Color::Red},
      {"Blue", sf::Color::Blue},
      {"Black", sf::Color::Black},
  };
  return carte[color];
}
sf::Vector2f Circle::position() const {
  return {static_cast<float>(x) - static_cast<float>(r) + 300.f,
          static_cast<float>(y) - static_cast<float>(r) + 300.f};
}
std::string Circle::dump(std::string const &indent) const {
  ostringstream oss;
  oss << indent << "Circle " << "\"" << label << "\", " << "x: " << x << ", "
      << "y: " << y << ", " << "r: " << r << ", " << "color: " << "\"" << color
      << "\"" << endl;
  return oss.str();
}
