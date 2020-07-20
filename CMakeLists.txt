cmake_minimum_required(VERSION 3.5)

project(qml-mac-dock-menu-example LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Quick Widgets REQUIRED)

add_executable(qml-mac-dock-menu-example
  main.cpp
  dockmenu.cpp
  qml.qrc
)

target_compile_definitions(qml-mac-dock-menu-example
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(qml-mac-dock-menu-example
  PRIVATE Qt5::Core Qt5::Quick Qt5::Widgets)
