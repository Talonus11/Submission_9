# The minimum version of CMake Required 
cmake_minimum_required (VERSION 2.6)

# Any ppoject name will suffice, this has connotaions when using advanced CMake Features
project (Assignment1_Ritesh_KUMAR_11656978)

# CMake will now create the Makefiles that are needed to make an executable "main" that requires "main.cpp" and "lidar.cpp" 
add_executable(main main.cpp lidar.cpp)

add_definitions(-std=c++11)





