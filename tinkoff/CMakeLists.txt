# only for cmake --version >= 3.5.1
cmake_minimum_required(VERSION 3.5.1)

# project name
project(vect)

# creates the variable EXEC and sets it to hello
set(EXEC exe)

# set the C++17 standard
set(CMAKE_CXX_STANDARD 17)

# I../includes
include_directories(contrib)

# puts all .cpp files inside src to the SOURCES variable
file(GLOB SOURCES src/*.cpp contrib/gtest/*.cc)

# compiles the files defined by SOURCES to generante the executable defined by EXEC
add_executable(${EXEC} ${SOURCES})

# set the threads flag
set(THREADS_PREFER_PTHREAD_FLAG ON)
set(CMAKE_BUILD_TYPE Debug)
find_package(Threads)
target_link_libraries(${EXEC} Threads::Threads)

