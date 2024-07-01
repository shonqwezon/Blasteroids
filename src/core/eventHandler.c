//
// Created by Shon on 07.06.2024.
//

#include "eventHandler.h"

#include <stdio.h>

void run_event_handler() {
    queue = al_create_event_queue();
    al_wait_for_event(queue, &event);

    if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
        switch (event.keyboard.keycode) {
            case ALLEGRO_KEY_LEFT:
                printf("Pressed Key left");
                break;
            case ALLEGRO_KEY_RIGHT:
                printf("Pressed Key right");
                break;
            case ALLEGRO_KEY_SPACE:
                printf("Pressed Key space");
                break;
        }
    }
}
