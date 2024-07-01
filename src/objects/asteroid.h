//
// Created by Shon on 07.06.2024.
//

#ifndef BLASTEROIDS_ASTEROID_H
#define BLASTEROIDS_ASTEROID_H

#include <allegro5/allegro.h>

typedef struct {
    float sx;
    float sy;
    float heading;
    float twist;
    float speed;
    float rot_velocity;
    float scale;
    ALLEGRO_COLOR color;
} Asteroid;

void draw_asteroid(const Asteroid *a);

#endif //BLASTEROIDS_ASTEROID_H
