cmake_minimum_required(VERSION 3.12)

set(MASTER_PROJECT OFF)
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
	set(MASTER_PROJECT ON)
endif ()

project(nova)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>")

option(NOVA_BUILD_TESTS "Build nova unit tests." ${MASTER_PROJECT})

add_subdirectory(nova)

if (NOVA_TESTS)
	message(STATUS "[nova]: building unit tests is enabled")
	add_subdirectory(external/doctest)
	add_subdirectory(utests)
endif(NOVA_TESTS)
