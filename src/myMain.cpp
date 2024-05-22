#include "myMain.h"
#include "Circle.h"
#include "Group.h"
#include "SFML/Graphics.hpp"
#include "pugixml.hpp"
#include <iostream>
using namespace std;

int myMain() {
  // create the window
  sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
  // Recup XML
  pugi::xml_document doc;
  if (auto result = doc.load_file("/home/kali-user/Documents/tsp/pre-djin/"
                                  "outilVisualisation/ressources/visage.xml");
      !result) {
    std::cerr << "Could not open file visage.xml because "
              << result.description() << std::endl;
    return 1;
  }
  Group g{doc.child("Drawing")};
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
    window.clear(sf::Color::White);
    g.affiche(window);
    // draw everything here...
    // window.draw(...);

    // end the current frame
    window.display();
  }

  return 0;
}
