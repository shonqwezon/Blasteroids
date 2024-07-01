#include <allegro5/allegro.h>
#include <stdio.h>

#include "core/eventHandler.h"
#include "objects/spaceship.h"

int main() {
    if(!al_init()) {
        printf("Can't init!\n");
    }
    al_set_app_name("Test");
    ALLEGRO_DISPLAY * display = al_create_display(1600, 900);
    if(!display) {
        printf("Error!\n");
    }
    run_event_handler();
    al_uninstall_system();
    return 0;
}
