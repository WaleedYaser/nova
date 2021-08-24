cmake_minimum_required(VERSION 3.12)

add_library(nova INTERFACE
	include/nova/types.h
	include/nova/math.h
	include/nova/vec2.h
	include/nova/vec3.h
	include/nova/vec4.h
	include/nova/mat2.h
	include/nova/mat3.h
	include/nova/mat4.h
)

target_include_directories(nova INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
