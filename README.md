# HelloCMake: Simple CMake project example
* main: main executable
This is main executable will call functions built from shared library calc

* calc: shared library
This is shared library, which provide `add`, `sub`, `mul` and `div` four simple functions.

* test: test project (executable)
A simple testing project, which is using boost unit test framework.

# How to build and install

For cmake project, it is strongly recommended to do outsource build,
so that you won't mess up your source folder.
Make sure you are OUTSIDE current source folder (where top level CMakeLists.txt), issue the following commands:
```bash
# Build a Debug version, and it will be installed in ./dist
cmake HelloCMake -B build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_ISNTALL_PREFIX=./dist

# Build it use available compilers (usually gcc under linux) 
cmake --build build

# You can also add -j parameter to do parallel build
# Build with 4 processes
cmake --build build -j4

# Install it
# For executable `main` and `CalcTest`, they will be installed under ./dist/bin folder;
# For shared library `libcalc.so`, it will be installed under ./dist/lib folder.
cmake --install build
```

# How to run
``` bash
# Run main application
./dist/bin/main

# Run test cases
./dist/bin/CalcTest

# Run test cases: show detailed information
# https://www.boost.org/doc/libs/1_71_0/libs/test/doc/html/index.html
./dist/bin/CalcTest -r detailed

# Show boost unit test help information
./dist/bin/CalcTest --help

# Run test cases with ctest
# Make sure you are in build folder, otherwise you will get the follow error:
# `No test configuration file found!` or `No tests were found!!!`
cd build  
ctest

# It is possible to run ctest outside the build folder,
# but it is not supported until cmake 3.20:
# https://cmake.org/cmake/help/v3.20/manual/ctest.1.html
# If your cmake version is 3.20 or above, you can issue ctest command 
# and specify where to find the tests
ctest --test-dir build
```

![HelloCMake](https://github.com/bgyu/HelloCMake/actions/workflows/c-cpp.yml/badge.svg)
![HelloCMake](https://github.com/github/docs/actions/workflows/c-cpp.yml/badge.svg?event=push)
