cmake_minimum_required(VERSION 3.16)

project(Hello VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_INSTALL_RPATH $ORIGIN)

# set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/sanitizers-cmake/cmake" ${CMAKE_MODULE_PATH})

# Use -fsanitize=address to detect buffer overflow related issues
# See: https://github.com/google/sanitizers/wiki/AddressSanitizer
# Use valgrind to detect memory issues
# set(MSAN_OPTIONS -fsanitize=memory -fno-omit-frame-pointer -g)
set(ASAN_OPTIONS -fsanitize=address -fno-omit-frame-pointer -g)
add_compile_options(${ASAN_OPTIONS})
add_link_options(${ASAN_OPTIONS})

add_subdirectory(calc)
add_subdirectory(main)

include(CTest)
if (BUILD_TESTING)
    add_subdirectory(test)
endif()
