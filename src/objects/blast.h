//
// Created by Shon on 07.06.2024.
//

#ifndef BLASTEROIDS_BLAST_H
#define BLASTEROIDS_BLAST_H

#include <allegro5/allegro.h>

#include "spaceship.h"

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
} Blast;

void init_blast(Blast *b, Spaceship *s);

void free_blast(Blast *b);

void draw_blast(const Blast *b);

#endif //BLASTEROIDS_BLAST_H
