//
// Created by Shon on 02.07.2024.
//

#ifndef BLASTEROIDS_RENDER_H
#define BLASTEROIDS_RENDER_H

#include <allegro5/allegro.h>

#include "../utils/common.h"
#include "../objects/objects.h"
#include "../utils/logger.h"

static Spaceship *spaceship;

static ALLEGRO_EVENT_QUEUE *queue;
static ALLEGRO_EVENT event;

void *run_render(ALLEGRO_THREAD *thr, void *arg);

#endif //BLASTEROIDS_RENDER_H
