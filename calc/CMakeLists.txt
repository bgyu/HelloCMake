cmake_minimum_required(VERSION 3.16)

project(calc VERSION 1.0)

add_library(${PROJECT_NAME} SHARED)

target_sources(${PROJECT_NAME} PRIVATE
    add.cpp sub.cpp mul.cpp div.cpp calc.h
)

install(
    TARGETS ${PROJECT_NAME}
    CONFIGURATIONS ${CMAKE_BUILD_TYPE}
)
