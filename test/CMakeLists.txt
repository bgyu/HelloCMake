cmake_minimum_required(VERSION 3.16)

project(CalcTest VERSION 1.0 DESCRIPTION "Testing project")

# Testing executable needs to know where to find the shared library
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_RPATH}:${CMAKE_INSTALL_PREFIX}/lib")

# We are using boost unit test framework
find_package(Boost 1.71 REQUIRED COMPONENTS unit_test_framework)
if (NOT Boost_FOUND)
    message(FATAL "Can't find boost 1.71")
endif()

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE testcalc.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/calc)
target_link_libraries(${PROJECT_NAME} PRIVATE Boost::unit_test_framework calc)

# Add test to ctest, so that you can run the the tests with `ctest` command
# Note: this will add all tests in the project as a whole.
# If you want to pretty out put each test cases, you can add one by one,
# or write a cmake script to find cases from source files:
# https://eb2.co/blog/2015/06/driving-boost.test-with-cmake/
# add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

# https://cmake.org/cmake/help/latest/command/add_test.html
# boost test filer: --run_test=test_suite/test_case
# see: https://www.boost.org/doc/libs/1_71_0/libs/test/doc/html/boost_test/runtime_config/test_unit_filtering.html
# Add tests one by one:
add_test(NAME TestAdd/TestAdd1 COMMAND ${PROJECT_NAME} --run_test=TestAdd/TestAdd1)
add_test(NAME TestAdd/TestAdd2 COMMAND ${PROJECT_NAME} --run_test=TestAdd/TestAdd2)
add_test(NAME TestAdd/TestAdd3 COMMAND ${PROJECT_NAME} --run_test=TestAdd/TestAdd3)

install(
    TARGETS ${PROJECT_NAME}
    CONFIGURATIONS ${CMAKE_BUILD_TYPE}
)
