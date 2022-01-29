cmake_minimum_required(VERSION 3.16)

project(Hello VERSION 1.0)

# Make sure c++17 standard is used
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Turn on PIC/PIE
# https://cmake.org/cmake/help/latest/prop_tgt/POSITION_INDEPENDENT_CODE.html
# This is required for shared library. By default it is turned on.
# We just set it explicitly for demonstration.
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Make sure the shared library can be found if it is in the same folder with executable.
# For example, you put `main` executable and `libcalc.so` in the same folder,
# then run ./main, it will report `libcalc.so` not found without the following setting.
set(CMAKE_INSTALL_RPATH $ORIGIN)

# Your own cmake script folder.
# You can write some cmake script and put in the following folder
# and use loaded by `include()` or `find_package()`
# https://cmake.org/cmake/help/latest/variable/CMAKE_MODULE_PATH.html
# set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

#[[ Diagnostic reference: (MUST BUILD WITH `DEBUG` VERSION)
# Sanitize: with address sanitize or memory sanitize you can 
# detect if your program has stack overflow issue or memory leak issue etc.
# This is supported by clang compiler.
# See https://clang.llvm.org/docs/AddressSanitizer.html
# https://clang.llvm.org/docs/MemorySanitizer.html
# Other sanitizer: https://clang.llvm.org/docs/index.html
# Use -fsanitize=address to detect buffer overflow related issues
# See: https://github.com/google/sanitizers/wiki/AddressSanitizer
# Use valgrind to detect memory issues
# Memory Sanitize
# set(MSAN_OPTIONS -fsanitize=memory -fno-omit-frame-pointer -g)
# Address Sanitize
# set(ASAN_OPTIONS -fsanitize=address -fno-omit-frame-pointer -g)
# add_compile_options(${ASAN_OPTIONS})
# add_link_options(${ASAN_OPTIONS})
#]]

add_subdirectory(calc)
add_subdirectory(main)

include(CTest)  # Turn on `BUILD_TESTING` by default
if (BUILD_TESTING)
    add_subdirectory(test)
endif()
