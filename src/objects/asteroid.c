//
// Created by Shon on 07.06.2024.
//

#include <allegro5/allegro_primitives.h>
#include "asteroid.h"

void draw_asteroid(const Asteroid *a) {
    al_draw_line(-20, 20, -25, 5, a->color, 2.0f);
    al_draw_line(-25, 5, -25, -10, a->color, 2.0f);
    al_draw_line(-25, -10, -5, -10, a->color, 2.0f);
    al_draw_line(-5, -10, -10, -20, a->color, 2.0f);
    al_draw_line(-10, -20, 5, -20, a->color, 2.0f);
    al_draw_line(5, -20, 20, -10, a->color, 2.0f);
    al_draw_line(20, -10, 20, -5, a->color, 2.0f);
    al_draw_line(20, -5, 0, 0, a->color, 2.0f);
    al_draw_line(0, 0, 20, 10, a->color, 2.0f);
    al_draw_line(20, 10, 10, 20, a->color, 2.0f);
    al_draw_line(10, 20, 0, 15, a->color, 2.0f);
    al_draw_line(0, 15, -20, 20, a->color, 2.0f);
}
