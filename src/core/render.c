//
// Created by Shon on 02.07.2024.
//

#include "render.h"

void *run_render(ALLEGRO_THREAD *thr, void *arg) {
    const EventInfo *eventInfo = (EventInfo*) arg;

    ALLEGRO_DISPLAY *display = al_create_display(600, 400);
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();

    while(eventInfo->isRun) {

    }

    al_destroy_event_queue(queue);
    al_destroy_display(display);

    return NULL;
}
