//
// Created by Shon on 07.06.2024.
//

#include <allegro5/allegro_primitives.h>
#include "game.h"

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

    return true;
}

void free_modules() {
    debug("Finish event handler");
    al_uninstall_keyboard();
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
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
        display_game(interpolation);
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


}

void display_game(float dt) {

}
