//
// Created by Shon on 02.07.2024.
//

#include "render.h"

void *run_render(ALLEGRO_THREAD *thr, void *arg) {
    const EventInfo *eventInfo = (EventInfo*) arg;
    debug("Render: %x", eventInfo);
    ALLEGRO_TIMER *timer = al_create_timer(1);

    spaceship = malloc(sizeof(Spaceship));

    queue = al_create_event_queue();
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_start_timer(timer);

    while(eventInfo->isRun) {
        al_wait_for_event(queue, &event);
        if (event.type != ALLEGRO_EVENT_TIMER) continue;

        if(eventInfo->keys[ALLEGRO_KEY_UP])
            spaceship->sx -= 2;
        if(eventInfo->keys[ALLEGRO_KEY_DOWN])
            spaceship->sx += 2;
        if(eventInfo->keys[ALLEGRO_KEY_LEFT])
            spaceship->sy += 2;
        if(eventInfo->keys[ALLEGRO_KEY_RIGHT])
            spaceship->sx -= 2;

        debug("(%d, %d)", spaceship->sx, spaceship->sy);

//        al_clear_to_color(al_map_rgb(0, 0, 0));
//        draw_spaceship(spaceship);
//        al_flip_display();
    }

    al_destroy_event_queue(queue);

    free(spaceship);

    return NULL;
}
