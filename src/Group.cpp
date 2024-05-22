#include "Group.h"
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/CircleShape.hpp"
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
  // auto toto = new char[100000]; creation fuite
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
void Group::affiche(sf::RenderWindow &fenêtre) const {
  for (auto const &c : children) {
    sf::CircleShape cercle{10};
    cercle.setFillColor(c.color);
    fenêtre.draw(cercle);
  }
  for (auto const &g : enfant_groupe) {
    g.affiche(fenêtre);
  }
  return;
}
