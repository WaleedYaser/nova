cmake_minimum_required(VERSION 3.12)

project(nova)

if ( CMAKE_COMPILER_IS_GNUCC )
	set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()
if ( MSVC )
	set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W4")
endif()

add_subdirectory(nova)

add_executable(nova-exe main.cpp)
target_link_libraries(nova-exe PUBLIC nova)