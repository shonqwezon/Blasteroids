//
// Created by Shon on 07.06.2024.
//

#include "game.h"

#include <allegro5/allegro_primitives.h>

#include "../utils/logger.h"
#include "../utils/config.h"

bool init_modules() {
    debug("Run event handler");

    if (!al_install_keyboard()) {
        error(PROC, "Can't init keyboard");
        return false;
    }

    if (!al_init_primitives_addon()) {
        error(PROC, "Can't init primitives");
        return false;
    }

    queue = al_create_event_queue();
    if (!queue) {
        error(PROC, "Can't init queue");
        return false;
    }

    font = al_load_font("../data/font.ttf", 16, 0);
    if (!font) {
        error(PROC, "Can't create font");
        return false;
    }

    frames = 0;
    fps = 0;
    prevTime = al_get_time();

    spaceship = malloc(sizeof(Spaceship));
    init_spaceship(spaceship);
    return true;
}

void free_modules() {
    debug("Finish event handler");
    al_uninstall_keyboard();
    al_destroy_event_queue(queue);
    al_destroy_font(font);

    free_spaceship(spaceship);
}

int getCurrentTime() {
    return (int)(al_get_time() * 1000);
}

void run_game(ALLEGRO_DISPLAY *display) {
    if (!init_modules()) {
        free_modules();
        return;
    }
    isRun = true;

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));

    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();

    int loops;
    float interpolation;
    int gameTick = getCurrentTime();

    const int GAME_STEP = 1000 / get_cfg()->tps;
    const int MAX_FRAMESKIP = 5;

    while (isRun) {
        loops = 0;
        while (getCurrentTime() > gameTick && loops < MAX_FRAMESKIP) {
            update_game();
            gameTick += GAME_STEP;
            loops++;
        }
        interpolation = (float)(getCurrentTime() + GAME_STEP - gameTick) / (float)GAME_STEP;
        calc_fps();
        display_game(interpolation);

        al_rest(0.001);
    }

    free_modules();
}

void update_game() {
    while (al_get_next_event(queue, &event)) {
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            isRun = false;
            break;
        }
        else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            keys[event.keyboard.keycode] = true;
        }
        else if (event.type == ALLEGRO_EVENT_KEY_UP) {
            keys[event.keyboard.keycode] = false;
        }
    }

    spaceship->vx = (-keys[ALLEGRO_KEY_UP] + keys[ALLEGRO_KEY_DOWN]) * spaceship->speed;
    spaceship->vy = (-keys[ALLEGRO_KEY_RIGHT] + keys[ALLEGRO_KEY_LEFT]) * spaceship->speed;

    spaceship->toX += spaceship->vx;
    spaceship->toY += spaceship->vy;
    if(!spaceship->vx) spaceship->toX = spaceship->x;
    if(!spaceship->vy) spaceship->toY = spaceship->y;

    if(keys[ALLEGRO_KEY_SPACE]) {

    }
}

void display_game(float dt) {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    spaceship->x = spaceship->toX + spaceship->vx * dt;
    spaceship->y = spaceship->toY + spaceship->vy * dt;

    draw_spaceship(spaceship);
    al_draw_textf(font, al_map_rgb(255, 255, 255), 10, 10, 0, "FPS: %.2f", fps);

    al_flip_display();
}

void calc_fps() {
    frames++;

    double currTime = al_get_time();
    if (currTime - prevTime >= 1.0) {
        fps = frames / (currTime - prevTime);
        prevTime = currTime;
        frames = 0;
    }
}
