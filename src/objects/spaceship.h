//
// Created by Shon on 07.06.2024.
//

#ifndef BLASTEROIDS_SPACESHIP_H
#define BLASTEROIDS_SPACESHIP_H

#include <allegro5/allegro.h>

typedef struct {
    float x;
    float y;
    float toX;
    float toY;
    float vx;
    float vy;

    float heading;
    float speed;
    int gone;
    ALLEGRO_COLOR color;
} Spaceship;

void init_spaceship(Spaceship *s);

void free_spaceship(Spaceship *s);

void draw_spaceship(const Spaceship *s);

#endif //BLASTEROIDS_SPACESHIP_H
