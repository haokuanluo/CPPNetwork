set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "-g")
set(CMAKE_CXX_FLAGS "-o0")

add_executable(echo_server EchoServer.cpp)
target_link_libraries(echo_server netlib)

add_executable(echo_client EchoClient.cpp)
target_link_libraries(echo_client netlib)