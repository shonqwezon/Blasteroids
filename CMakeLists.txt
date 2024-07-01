cmake_minimum_required(VERSION 3.27)
project(Blasteroids C)

set(CMAKE_C_STANDARD 17)

set(core
        src/core/eventHandler.c
        src/core/eventHandler.h)

set(utils
        src/utils/logging.c
        src/utils/logging.h
        src/utils/config.c
        src/utils/config.h
        src/utils/settings.h)

set(objects
        src/objects/spaceship.c
        src/objects/spaceship.h
        src/objects/blast.c
        src/objects/blast.h
        src/objects/asteroid.c
        src/objects/asteroid.h)

add_executable(Blasteroids
        src/main.c
        ${core}
        ${objects}
        ${utils})

target_link_libraries(Blasteroids
        allegro
        allegro_main
        allegro_primitives
        allegro_image
        allegro_font
        allegro_ttf)
