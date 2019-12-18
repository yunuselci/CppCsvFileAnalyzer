cmake_minimum_required(VERSION 3.15)
project(TermProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(TermProject main.cpp cppVector.cpp cppVector.h rowReader.cpp rowReader.h hashTable.cpp hashTable.h)