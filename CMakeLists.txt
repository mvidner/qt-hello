# libqt5-qtdoc.rpm
# file:///usr/share/doc/packages/qt5/qtdoc/cmake-manual.html
cmake_minimum_required(VERSION 2.8.11)

project(testproject)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)

add_library(plugin SHARED plugin.cpp)
# Use the Widgets module from Qt 5.
target_link_libraries(plugin Qt5::Widgets)

# Tell CMake to create the helloworld executable
add_executable(helloworld main.cpp)
# Link the "plugin" (now a shared library)
target_link_libraries(helloworld dl)
