//
// Created by Shon on 07.06.2024.
//

#ifndef BLASTEROIDS_BLAST_H
#define BLASTEROIDS_BLAST_H

#include <allegro5/allegro.h>

typedef struct {
    float sx;
    float sy;
    float heading;
    float speed;
    int gone;
    ALLEGRO_COLOR color;
} Blast;

#endif //BLASTEROIDS_BLAST_H
