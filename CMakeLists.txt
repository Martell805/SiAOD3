cmake_minimum_required(VERSION 3.20)
project(SiAOD3)

set(CMAKE_CXX_STANDARD 23)

add_executable(SiAOD3 main.cpp phoneBookUtil.h phoneBookUtil.cpp HashTable.h HashTable.cpp BinHashTable.h BinHashTable.cpp)
