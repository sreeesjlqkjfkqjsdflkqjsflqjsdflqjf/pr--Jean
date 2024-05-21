#include "Circle.h"
#include <sstream>

using namespace std;

Circle::Circle(const pugi::xml_node &node) {
  label = node.attribute("label").as_string();
  x = node.attribute("x").as_double();
  y = node.attribute("y").as_double();
  r = node.attribute("r").as_double();
  color = node.attribute("color").as_string();
}
std::string Circle::dump(std::string const &indent) const {
  ostringstream oss;
  oss << indent << "Circle " << "\"" << label << "\", " << "x: " << x << ", "
      << "y: " << y << ", " << "r: " << r << ", " << "color: " << "\"" << color
      << "\"" << endl;
  return oss.str();
}
