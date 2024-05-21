#include "myMain.h"
#include "Circle.h"
#include "Group.h"
#include "SFML/Graphics.hpp"
#include "pugixml.hpp"
#include <iostream>
using namespace std;
int myMain() {
  std::string sc = R"(<?xml version = "1.0 "?>
                   <Group label="testGroupHybrid" x="0" y="1">
      <Circle label="testCircle" x="2" y="3" r="4" color="Black" />
      <Circle label="testCircle" x="2" y="3" r="4" color="Black" />
      <Group label="testGroup" x="5" y="6">
      <Circle label="testCircle" x="2" y="3" r="4" color="Black"/>
    </Group></Group> )";
  pugi::xml_document doc;
  if (auto result = doc.load_file("/home/kali-user/Documents/tsp/pre-djin/"
                                  "outilVisualisation/ressources/visage.xml");
      !result) {
    std::cerr << "Could not open file visage.xml because "
              << result.description() << std::endl;
    return 1;
  }
  // pugi::xml_document doc;
  // pugi::xml_parse_result result = doc.load_string(sc.c_str());
  // if (!result) {
  //   cerr << "FOIRÉ! : " << result.description();
  //   exit(1);
  // }
  Group g{doc.child("Drawing")};
  cout << g.dump() << std::endl;
  return 0;
}

int main() {
  // create the window
  sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

  // run the program as long as the window is open
  while (window.isOpen()) {
    // check all the window's events that were triggered since the last
    // iteration of the loop
    sf::Event event;
    while (window.pollEvent(event)) {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed)
        window.close();
    }

    // clear the window with black color
    window.clear(sf::Color::Black);

    // draw everything here...
    // window.draw(...);

    // end the current frame
    window.display();
  }

  return 0;
}
