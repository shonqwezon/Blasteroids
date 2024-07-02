//
// Created by Shon on 07.06.2024.
//

#include <allegro5/allegro_primitives.h>
#include "eventHandler.h"

#include "../utils/logger.h"

void run_event_handler(ALLEGRO_DISPLAY *display) {
    al_install_keyboard();
    al_init_primitives_addon();

    queue = al_create_event_queue();
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));

    s = malloc(sizeof(Spaceship));
    s->color = al_map_rgb(100, 100, 100);
    s->sx = 100;
    s->sy = 100;
    s->heading = -ALLEGRO_PI / 2;

    bool isRun = true;
    while (isRun) {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        draw_spaceship(s);
        al_flip_display();

        while (al_get_next_event(queue, &event)) {
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
    }
    free(s);
    al_destroy_event_queue(queue);
    al_uninstall_keyboard();
}

void keyboard_handler() {
    switch (event.keyboard.keycode) {
        case ALLEGRO_KEY_LEFT:
            debug("Pressed Key left");
            s->sy += 1;
            break;
        case ALLEGRO_KEY_RIGHT:
            debug("Pressed Key right");
            s->sy -= 1;
            break;
        case ALLEGRO_KEY_UP:
            debug("Pressed Key up");
            s->sx -= 1;
            break;
        case ALLEGRO_KEY_DOWN:
            debug("Pressed Key down");
            s->sx += 1;
            break;
        case ALLEGRO_KEY_SPACE:
            debug("Pressed Key space");
            break;
    }
}
