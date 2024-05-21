#include "Group.h"
#include <sstream>

using namespace std;
Group::Group(const pugi::xml_node &nodeGroup) {
  label = nodeGroup.attribute("label").as_string();
  x = nodeGroup.attribute("x").as_double();
  y = nodeGroup.attribute("y").as_double();
  for (auto cercle : nodeGroup.children("Circle")) {
    this->children.push_back(Circle{cercle});
  }
  for (auto groupe : nodeGroup.children("Group")) {
    this->enfant_groupe.push_back(Group{groupe});
  }
}
std::string Group::dump(std::string const &indent) const {
  ostringstream oss;
  oss << indent << "Group " << "\"" << label << "\", " << "x: " << x << ", "
      << "y: " << y << ", " << "children: [" << endl;
  for (auto const &c : children) {
    oss << c.dump(indent + "| ");
  }
  for (auto const &g : enfant_groupe) {
    oss << g.dump(indent + "| ");
  }
  oss << indent << "]" << endl;
  return oss.str();
}
