add_library(nova INTERFACE)

target_include_directories(nova INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_options(nova INTERFACE
	 $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>: -Werror -Weverything>
	 $<$<CXX_COMPILER_ID:GNU>: -Wall -Wextra>
	 $<$<CXX_COMPILER_ID:MSVC>: /WX>
)
