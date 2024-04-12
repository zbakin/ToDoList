cmake_minimum_required(VERSION 3.27)
project(ToDoList)

set(CMAKE_CXX_STANDARD 20)

add_executable(ToDoList main.cpp
        Task.cpp
        ToDoList.h
        ToDoList.cpp
)

add_subdirectory(deps/libpqxx build-pqxx)
target_link_libraries(ToDoList PRIVATE pqxx)