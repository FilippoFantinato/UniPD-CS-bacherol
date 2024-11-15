cmake_minimum_required(VERSION 3.16)
project(sliders)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(Qt5_DIR "/home/filippofantinato/Qt/5.9.9/gcc_64/lib/cmake/Qt5/")

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(sliders main.cpp LCDRange.cpp MyWidget.cpp MyWidget.h)
target_link_libraries(sliders Qt5::Widgets)
