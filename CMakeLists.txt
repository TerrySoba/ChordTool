# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.28)

project(ChordTool)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)

# Find the required Qt6 packages
find_package(Qt6 COMPONENTS Core Widgets REQUIRED)
qt_standard_project_setup()

# Create the executable
qt_add_executable(${PROJECT_NAME}
    src/main.ui
    src/main.cpp
    src/MainWindow.cpp
    src/MainWindow.h
)


add_library(ChordToolLib STATIC
    src/note.cpp
    src/note.h
    src/chord.cpp
    src/chord.h
)


# Link the required Qt6 libraries
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Widgets)

add_executable(ChordToolTests
    tests/testmain.cpp
    tests/note_test.cpp
    tests/chord_test.cpp
)

target_link_libraries(ChordToolTests PRIVATE
    ChordToolLib)

target_include_directories(ChordToolTests PRIVATE
    3rdparty/doctest
    src)

