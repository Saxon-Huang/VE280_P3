cmake_minimum_required(VERSION 3.15)
project(VE280_P3)

set(CMAKE_CXX_STANDARD 11)

add_executable(VE280_P3 main.cpp card.cpp card.h deck.cpp deck.h hand.cpp hand.h player.cpp player.h rand.cpp rand.h)