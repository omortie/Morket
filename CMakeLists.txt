project(Morketie)

cmake_minimum_required(VERSION 3.16)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets Network)

set(SRCS
        main.cpp morketiewindow.cpp serverinterface.cpp)

set(HDRS
        morketiewindow.h serverinterface.h)

set(UIS
        morketiewindow.ui)

set(RES
        )

include_directories(${CMAKE_BINARY_DIR})

add_executable(Morketie ${SRCS} ${HDRS} ${UIS} ${RES})
target_link_libraries(Morketie Qt5::Core Qt5::Widgets Qt5::Network)
target_link_libraries(Morketie htmlcxx)
