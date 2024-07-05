//
// Created by Shon on 07.06.2024.
//

#include "spaceship.h"

#include <allegro5/transformations.h>
#include <allegro5/allegro_primitives.h>

#include "../utils/config.h"


void draw_spaceship(const Spaceship *s) {
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_rotate_transform(&transform, s->heading);
    al_translate_transform(&transform, s->x, s->y);
    al_use_transform(&transform);

    al_draw_line(-12, 13, 0, -15, s->color, 5.0f);
    al_draw_line(0, -15, 12, 13, s->color, 5.0f);
    al_draw_line(-10, 8, -3, 8, s->color, 5.0f);
    al_draw_line(10, 8, 3, 8, s->color, 5.0f);

    al_identity_transform(&transform);
    al_use_transform(&transform);
}

void init_spaceship(Spaceship *s) {
    s->toX = get_cfg()->display.width * 0.8;
    s->toY = get_cfg()->display.height * 0.5;
    s->vx = 0;
    s->vy = 0;

    s->heading = -ALLEGRO_PI / 2;
    s->speed = 10;
    s->gone = 0;
    s->color = al_map_rgb(100, 100, 50);
}

void free_spaceship(Spaceship *s) {
    free(s);
}
