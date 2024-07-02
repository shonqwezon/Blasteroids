//
// Created by Shon on 07.06.2024.
//

#include "eventHandler.h"

#include "../utils/logger.h"

void run_event_handler(ALLEGRO_DISPLAY *display) {
    al_install_keyboard();

    queue = al_create_event_queue();
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));

    bool isRun = true;
    while (isRun) {
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_KEY_CHAR:
                keyboard_handler();
                break;
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                debug("Pressed close button");
                isRun = false;
                break;
        }
    }

    al_destroy_event_queue(queue);
    al_uninstall_keyboard();
}

void keyboard_handler() {
    switch (event.keyboard.keycode) {
        case ALLEGRO_KEY_LEFT:
            debug("Pressed Key left");
            break;
        case ALLEGRO_KEY_RIGHT:
            debug("Pressed Key right");
            break;
        case ALLEGRO_KEY_UP:
            debug("Pressed Key up");
            break;
        case ALLEGRO_KEY_DOWN:
            debug("Pressed Key down");
            break;
        case ALLEGRO_KEY_SPACE:
            debug("Pressed Key space");
            break;
    }
}
