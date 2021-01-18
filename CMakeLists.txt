# Project to Fiddle with Cmake and Catch2
# While also exploring some C++ async 
# concepts and git submodules

cmake_minimum_required(VERSION 3.19.0)

# Not sure if setting the compiler before the first
# project declaration is kosher -- but it prevents
# an infinite loop in Cmake Config step.

# use clang++ for compilation rather than g++
set(CMAKE_CXX_COMPILER /usr/bin/clang++)

# set C++ standard to c++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -Werror")

project(Catch2Fiddly)

# Catch2 target and test addition
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/Catch2)

# add the executable -- but have the sources stashed in a
# different directory
# use CMAKE_CURRENT_SOURCE_DIR because that is relative
# to this CMAKE_CURRENT_SOURCE_DIR
add_executable(DoSums
               ${CMAKE_CURRENT_SOURCE_DIR}/src/Summer.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

# We segregate the includes from the sources
target_include_directories(DoSums
                           PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Include the pthreads library because we may use the C++11 
# threading features
target_link_libraries(DoSums PRIVATE pthread) 

# Don't want gnu extensions to C++ standard
# Cmake defaults to this on
set_target_properties(DoSums
                      PROPERTIES CXX_EXTENSIONS OFF)

