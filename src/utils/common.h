//
// Created by Shon on 01.07.2024.
//

#ifndef BLASTEROIDS_COMMON_H
#define BLASTEROIDS_COMMON_H

#include <allegro5/allegro.h>

char *concat(const char *str1, const char *str2);

typedef struct {
    bool isRun;
    bool keys[ALLEGRO_KEY_MAX];
    ALLEGRO_DISPLAY *display;
} EventInfo;

#endif //BLASTEROIDS_COMMON_H
