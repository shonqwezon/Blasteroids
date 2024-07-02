//
// Created by Shon on 02.07.2024.
//

#ifndef BLASTEROIDS_RENDER_H
#define BLASTEROIDS_RENDER_H

#include <allegro5/allegro.h>

typedef struct {
    bool isRun;
    bool keys[5];
} EventInfo;

void *run_render(ALLEGRO_THREAD *thr, void *arg);

#endif //BLASTEROIDS_RENDER_H
