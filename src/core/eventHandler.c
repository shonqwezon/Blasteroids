//
// Created by Shon on 07.06.2024.
//

#include <allegro5/allegro_primitives.h>
#include "eventHandler.h"

#include "../utils/logger.h"

void run_event_handler(EventInfo *eventInfo) {
    debug("Run event handler");

    al_install_keyboard();
    al_init_primitives_addon();

    queue = al_create_event_queue();
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(eventInfo->display));

    eventInfo->isRun = true;
    while (eventInfo->isRun) {
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_KEY_DOWN:
            case ALLEGRO_EVENT_KEY_UP:
                if(event.type == ALLEGRO_EVENT_KEY_DOWN)
                    eventInfo->keys[event.keyboard.keycode] = true;
                else if(event.type == ALLEGRO_EVENT_KEY_UP)
                    eventInfo->keys[event.keyboard.keycode] = false;
                break;

            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                debug("Pressed close button");
                eventInfo->isRun = false;
                break;
        }
    }

    al_destroy_event_queue(queue);
    al_uninstall_keyboard();
    debug("Finish event handler");
}
