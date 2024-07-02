#include <allegro5/allegro.h>
#include <stdio.h>

#include "utils/config.h"
#include "utils/logger.h"
#include "utils/settings.h"

#include "core/eventHandler.h"

int main() {
    setbuf(stdout, 0);

    if (!al_init())
        error("Can't init allegro5");

    al_set_app_name(APP_NAME);

    char *currentDir = al_get_current_directory();
    CONFIG *cfg = cfg_init(currentDir);
    al_free(currentDir);

    ALLEGRO_DISPLAY *display = al_create_display(cfg->display.width, cfg->display.height);
    if (!display)
        error("Can't create display");

    debug("Run event handler");
    run_event_handler(display);
    debug("End event handler");


    al_destroy_display(display);
    cfg_free();

    al_uninstall_system();
    return 0;
}
