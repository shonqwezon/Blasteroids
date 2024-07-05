//
// Created by Shon on 07.06.2024.
//

#ifndef BLASTEROIDS_GAME_H
#define BLASTEROIDS_GAME_H

#include <allegro5/allegro.h>

#include "../utils/common.h"


static ALLEGRO_EVENT_QUEUE *queue;
static ALLEGRO_EVENT event;
static ALLEGRO_TIMER *timer;

static bool keys[ALLEGRO_KEY_MAX];
static bool isRun;

static bool init_modules();

static void free_modules();

static int getCurrentTime();

void run_game(ALLEGRO_DISPLAY *display);

void update_game();

void display_game(float dt);

#endif //BLASTEROIDS_GAME_H
