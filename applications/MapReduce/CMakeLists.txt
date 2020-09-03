add_executable(master Master.cpp)
target_link_libraries(master netlib)

add_executable(worker Worker.cpp)
target_link_libraries(worker netlib)