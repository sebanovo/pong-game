cmake_minimum_required(VERSION 3.10)
project(game C)

set(CMAKE_C_STANDARD 99)


include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(game src/main.c)
target_link_libraries(game libraylib.a)
target_link_libraries(game opengl32 gdi32 winmm) 