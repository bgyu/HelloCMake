cmake_minimum_required(VERSION 3.16)

project(main VERSION 1.0 DESCRIPTION "Main executable")

# Tell linker where to find shared library when running executable
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_RPATH}:${CMAKE_INSTALL_PREFIX}/lib")

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE main.cpp)
# Make sure headers for `calc` can be found
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/calc)
# Make sure link with `libcalc.so`. The executable needs it when running.
target_link_libraries(${PROJECT_NAME} PUBLIC calc)

install(
    TARGETS ${PROJECT_NAME}
    CONFIGURATIONS ${CMAKE_BUILD_TYPE}
)

# target_compile_options(${PROJECT_NAME} PRIVATE "-save-temps")
