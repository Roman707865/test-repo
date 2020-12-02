cmake_minimum_required(VERSION 3.0)

project(temptative_architecture)
add_subdirectory(OSMModule)

add_executable(temptative_architecture main.cpp)
target_link_libraries(temptative_architecture osmmodule)

install(TARGETS temptative_architecture RUNTIME DESTINATION bin)
