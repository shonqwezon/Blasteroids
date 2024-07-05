//
// Created by Shon on 07.06.2024.
//
#include <allegro5/allegro_primitives.h>
#include "spaceship.h"
#include <allegro5/transformations.h>


void draw_spaceship(const Spaceship *s) {
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_rotate_transform(&transform, s->heading);
    al_translate_transform(&transform, s->sx, s->sy);
    al_use_transform(&transform);

    al_draw_line(-8, 9, 0, -11, s->color, 3.0f);
    al_draw_line(0, -11, 8, 9, s->color, 3.0f);
    al_draw_line(-6, 4, -1, 4, s->color, 3.0f);
    al_draw_line(6, 4, 1, 4, s->color, 3.0f);
}

void init_spaceship(Spaceship *s) {
    s = malloc(sizeof(Spaceship));
    s->sx = 100;
    s->sy = 100;
    s->heading = -ALLEGRO_PI / 2;
    s->speed = 0;
    s->gone = 0;
    s->color = al_map_rgb(100, 100, 50);
}

void free_spaceship(Spaceship *s) {
    free(s);
}
