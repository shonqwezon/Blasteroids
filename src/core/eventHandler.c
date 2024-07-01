//
// Created by Shon on 07.06.2024.
//

#include "eventHandler.h"

#include "../utils/logger.h"

void run_event_handler() {
    queue = al_create_event_queue();
    al_wait_for_event(queue, &event);

    if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
        switch (event.keyboard.keycode) {
            case ALLEGRO_KEY_LEFT:
                debug("Pressed Key left");
                break;
            case ALLEGRO_KEY_RIGHT:
                debug("Pressed Key right");
                break;
            case ALLEGRO_KEY_SPACE:
                debug("Pressed Key space");
                break;
        }
    }
}
