//
// Created by Shon on 07.06.2024.
//

#ifndef BLASTEROIDS_SPACESHIP_H
#define BLASTEROIDS_SPACESHIP_H

#include <allegro5/allegro.h>

typedef struct {
    float sx;
    float sy;
    float heading;
    float speed;
    int gone;
    ALLEGRO_COLOR color;
} Spaceship;

void draw_spaceship(const Spaceship *s);

#endif //BLASTEROIDS_SPACESHIP_H
