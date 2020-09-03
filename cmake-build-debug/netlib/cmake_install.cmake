# Install script for directory: /Users/admin/C++_Network/netlib

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/admin/C++_Network/cmake-build-debug/netlib/libnetlib.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libnetlib.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libnetlib.a")
    execute_process(COMMAND "/Library/Developer/CommandLineTools/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libnetlib.a")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/Users/admin/C++_Network/netlib/Acceptor.h"
    "/Users/admin/C++_Network/netlib/Buffer.h"
    "/Users/admin/C++_Network/netlib/Callbacks.h"
    "/Users/admin/C++_Network/netlib/Channel.h"
    "/Users/admin/C++_Network/netlib/Connector.h"
    "/Users/admin/C++_Network/netlib/CountDownLatch.h"
    "/Users/admin/C++_Network/netlib/EPoller.h"
    "/Users/admin/C++_Network/netlib/EventLoop.h"
    "/Users/admin/C++_Network/netlib/EventLoopThread.h"
    "/Users/admin/C++_Network/netlib/InetAddress.h"
    "/Users/admin/C++_Network/netlib/Logger.h"
    "/Users/admin/C++_Network/netlib/noncopyable.h"
    "/Users/admin/C++_Network/netlib/TcpClient.h"
    "/Users/admin/C++_Network/netlib/TcpConnection.h"
    "/Users/admin/C++_Network/netlib/TcpServer.h"
    "/Users/admin/C++_Network/netlib/TcpServerSingle.h"
    "/Users/admin/C++_Network/netlib/ThreadPool.h"
    "/Users/admin/C++_Network/netlib/Timer.h"
    "/Users/admin/C++_Network/netlib/TimerQueue.h"
    "/Users/admin/C++_Network/netlib/Timestamp.h"
    )
endif()

