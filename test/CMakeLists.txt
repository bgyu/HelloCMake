cmake_minimum_required(VERSION 3.16)

project(CalcTest VERSION 1.0 DESCRIPTION "Testing project")

set(CMAKE_POSITION_INDEPENDENT_CODE OFF)
message(STATUS "in test: CMAKE_POSITION_INDEPENDENT_CODE=${CMAKE_POSITION_INDEPENDENT_CODE}")
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_RPATH}:${CMAKE_INSTALL_PREFIX}/lib")

find_package(Boost 1.71 REQUIRED COMPONENTS unit_test_framework)
if (NOT Boost_FOUND)
    message(FATAL "Can't find boost 1.71")
endif()

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE testcalc.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/calc)
target_link_libraries(${PROJECT_NAME} PRIVATE Boost::unit_test_framework calc)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

install(
    TARGETS ${PROJECT_NAME}
    CONFIGURATIONS ${CMAKE_BUILD_TYPE}
)
