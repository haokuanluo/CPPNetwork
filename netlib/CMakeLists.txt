set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-g")
set(CMAKE_CXX_FLAGS "-o0")
set(CMAKE_BUILD_TYPE Debug)

include_directories(${CMAKE_SOURCE_DIR}/netlib)

set(SOURCE_FILES
        EventLoop.cpp EventLoop.h
        EPoller.cpp EPoller.h
        Channel.cpp Channel.h
        Logger.h Logger.c
        noncopyable.h
        Acceptor.cpp Acceptor.h
        InetAddress.cpp InetAddress.h
        TcpConnection.cpp TcpConnection.h
        Callbacks.h
        TcpServerSingle.cpp TcpServerSingle.h
        TcpServer.cpp TcpServer.h
        Buffer.h Buffer.cpp
        ThreadPool.cpp ThreadPool.h
        Connector.cpp Connector.h
        TcpClient.cpp TcpClient.h
        CountDownLatch.h
        EventLoopThread.cpp EventLoopThread.h
        TimerQueue.cpp TimerQueue.h
        Timer.h
        Timestamp.h
        )

add_library(netlib STATIC ${SOURCE_FILES})
target_link_libraries(netlib pthread)

install(TARGETS netlib DESTINATION lib)
set(HEADERS
        Acceptor.h
        Buffer.h
        Callbacks.h
        Channel.h
        Connector.h
        CountDownLatch.h
        EPoller.h
        EventLoop.h
        EventLoopThread.h
        InetAddress.h
        Logger.h
        noncopyable.h
        TcpClient.h
        TcpConnection.h
        TcpServer.h
        TcpServerSingle.h
        ThreadPool.h
        Timer.h
        TimerQueue.h
        Timestamp.h
        )
install(FILES ${HEADERS} DESTINATION include)