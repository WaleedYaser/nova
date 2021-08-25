add_library(nova INTERFACE
	include/nova/defines.h
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

target_compile_options(nova INTERFACE
	 $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>: -Werror -Weverything>
	 $<$<CXX_COMPILER_ID:GNU>: -Wall -Wextra>
	 $<$<CXX_COMPILER_ID:MSVC>: /WX>
)
