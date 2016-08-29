cmake_minimum_required(VERSION 3.6)
project(SocketsWorkshop)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -pthread")

set(SOURCE_FILES main.c)
add_executable(SocketsWorkshop ${SOURCE_FILES})

link_directories("C:/Program Files (x86)/Windows Kits/8.1/Lib/winv6.3/um/x86")

target_link_libraries(SocketsWorkshop WS2_32)