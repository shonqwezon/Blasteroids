//
// Created by Shon on 07.06.2024.
//

#include "blast.h"

#include <allegro5/transformations.h>
#include <allegro5/allegro_primitives.h>

void draw_blast(const Blast *b) {
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_rotate_transform(&transform, b->heading);
    al_translate_transform(&transform, b->x, b->y);
    al_use_transform(&transform);

    al_draw_line(0, 0, 0, 15, b->color, 5.0f);

    al_identity_transform(&transform);
    al_use_transform(&transform);
}

void init_blast(Blast *b, Spaceship *s) {
    b->toX = s->x;
    b->toY = s->y;
    b->vx = 0;
    b->vy = 0;

    b->heading = s->heading;
    b->speed = s->speed * 1.5f;
    b->gone = 0;
    b->color = al_map_rgb(1, 1, 1);
}

void free_blast(Blast *b) {
    free(b);
}
