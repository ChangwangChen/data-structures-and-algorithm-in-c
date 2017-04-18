cmake_minimum_required(VERSION 2.8)

project(DataStructure)

add_library(List ${CMAKE_CURRENT_SOURCE_DIR}/lib/list.c)
add_executable(${PROJECT_NAME} "main.c")
target_link_libraries(${PROJECT_NAME} List)
