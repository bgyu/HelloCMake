# HelloCMake: Simple CMake project example
* main: main executable
* calc: share library
* test: test project (executable)

# How to build and install

For cmake project, it is strongly recommended to do outsource build,
so that you won't mess up your source folder.
Make sure you are outside current source folder, issue the following command:
```bash
# For debug versions, installation folder is ./dist
cmake HelloCMake -B build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_ISNTALL_PREFIX=./dist

# Build it 
cmake --build build

# Install it
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
cd build  # Make sure you are in build folder
ctest
```