set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "-g")
set(CMAKE_CXX_FLAGS "-o0")


cmake_minimum_required(VERSION 3.15)
project(C___Network)

set(CMAKE_CXX_STANDARD 17)
include_directories(${PROJECT_SOURCE_DIR})

#add_executable(myserver myserver.cpp network/connection.cpp)
#add_executable(myclient client.c)

add_subdirectory(netlib)
add_subdirectory(applications/MapReduce)




