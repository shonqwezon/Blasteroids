//
// Created by Shon on 07.06.2024.
//

#ifndef BLASTEROIDS_GAME_H
#define BLASTEROIDS_GAME_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

#include "../utils/common.h"
#include "../objects/objects.h"

const int MAX_BLASTS = 1000;

static ALLEGRO_EVENT_QUEUE *queue;
static ALLEGRO_EVENT event;
static ALLEGRO_FONT *font;

static Spaceship *spaceship;
static Blast *blasts[MAX_BLASTS];

static int frames;
static double fps;
static double prevTime;


static bool keys[ALLEGRO_KEY_MAX];
static bool isRun;

static bool init_modules();

static void free_modules();

static int getCurrentTime();

static void calc_fps();

void run_game(ALLEGRO_DISPLAY *display);

void update_game();

void display_game(float dt);

#endif //BLASTEROIDS_GAME_H
