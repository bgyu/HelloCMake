cmake_minimum_required(VERSION 3.16)

project(main VERSION 1.0 DESCRIPTION "Main executable")

set(CMAKE_POSITION_INDEPENDENT_CODE OFF)
message(STATUS "in main: CMAKE_POSITION_INDEPENDENT_CODE=${CMAKE_POSITION_INDEPENDENT_CODE}")
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_RPATH}:${CMAKE_INSTALL_PREFIX}/lib")
message(STATUS "in main: CMAKE_INSTALL_RPATH=${CMAKE_INSTALL_RPATH}")

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/calc)
target_link_libraries(${PROJECT_NAME} PUBLIC calc)

install(
    TARGETS ${PROJECT_NAME}
    CONFIGURATIONS ${CMAKE_BUILD_TYPE}
)

# target_compile_options(${PROJECT_NAME} PRIVATE "-save-temps")
