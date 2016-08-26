cmake_minimum_required(VERSION 3.6)
project(SocketsWorkshop)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -pthread -ws2_32")

set(SOURCE_FILES main.c)
add_executable(SocketsWorkshop ${SOURCE_FILES})

link_libraries()