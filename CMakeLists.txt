cmake_minimum_required (VERSION 2.8)

project (threadpool)

link_libraries(pthread)

add_executable(threadpool condition.c
               threadpool.c 
               test.c)
