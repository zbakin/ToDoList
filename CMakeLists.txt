cmake_minimum_required(VERSION 3.16.3)
project(ToDoList)

set(CMAKE_CXX_STANDARD 20)

add_executable(ToDoList main.cpp
        Task.cpp
        ToDoList.h
        ToDoList.cpp
        Database.h
        Database.cpp
)

add_subdirectory(lib/libpqxx build-pqxx)
target_link_libraries(ToDoList PRIVATE pqxx)