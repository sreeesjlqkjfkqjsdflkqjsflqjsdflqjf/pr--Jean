
file(GLOB SOURCES CONFIGURE_DEPENDS *.h *.cpp)
          FetchContent_Declare(
            sfml
            GIT_REPOSITORY https://github.com/SFML/SFML.git
            GIT_TAG 2.5.1
          )
          FetchContent_MakeAvailable(sfml)
add_library(src ${SOURCES} )
target_include_directories(src PUBLIC ./)
target_link_libraries(src PUBLIC pugixml)
target_link_libraries(src PUBLIC pugixml sfml-graphics)
