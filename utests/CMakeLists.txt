add_executable(utests
	src/main.cpp
	src/utests_math.cpp
	src/utests_vec2.cpp
	src/utests_vec3.cpp
	src/utests_vec4.cpp
	src/utests_mat2.cpp
	src/utests_mat3.cpp
	src/utests_mat4.cpp
)

target_link_libraries(utests PRIVATE
	doctest
	nova
)
