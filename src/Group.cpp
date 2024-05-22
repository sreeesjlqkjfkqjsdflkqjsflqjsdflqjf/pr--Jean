#include "Group.h"
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include <iostream>
#include <sstream>

using namespace std;
Group::Group(const pugi::xml_node &nodeGroup, double x, double y) {
  label = nodeGroup.attribute("label").as_string();
  this->x = nodeGroup.attribute("x").as_double() + x;
  this->y = nodeGroup.attribute("y").as_double() + y;
  for (auto cercle : nodeGroup.children("Circle")) {
    Circle test{cercle};
    test.x += this->x;
    test.y += this->y;
    this->children.push_back(test);
  }
  for (auto groupe : nodeGroup.children("Group")) {
    Group g{groupe, this->x, this->y};
    this->enfant_groupe.push_back(g);
  }
  // auto toto = new char[100000]; creation fuite
}
// Group::Group(const pugi::xml_node &nodeGroup) {
//   label = nodeGroup.attribute("label").as_string();
//   x = nodeGroup.attribute("x").as_double();
//   y = nodeGroup.attribute("y").as_double();
//   for (auto cercle : nodeGroup.children("Circle")) {
//     Circle test{cercle};
//     test.x += x;
//     test.y += y;
//     this->children.push_back(test);
//   }
//   for (auto groupe : nodeGroup.children("Group")) {
//     Group g{groupe};
//     g.x += x;
//     g.y += y;
//     std::cout << g.x << " " << g.y << std::endl;
//     this->enfant_groupe.push_back(g);
//   }
//   // auto toto = new char[100000]; creation fuite
// }
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
    sf::CircleShape cercle{c.rayon()};
    cercle.setFillColor(c.couleur());
    cercle.move(c.position());
    fenêtre.draw(cercle);
  }
  for (auto const &g : enfant_groupe) {
    g.affiche(fenêtre);
  }
  return;
}
