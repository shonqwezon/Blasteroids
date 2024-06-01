cmake_minimum_required(VERSION 3.27)
project(Blasteroids C)

set(CMAKE_C_STANDARD 17)

add_executable(Blasteroids src/main.c)

target_link_libraries(Blasteroids
        allegro
        allegro_main
        allegro_primitives
        allegro_image
        allegro_font
        allegro_ttf)
