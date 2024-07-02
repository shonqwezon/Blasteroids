#include <allegro5/allegro.h>
#include <stdio.h>

#include "utils/config.h"
#include "utils/logger.h"
#include "utils/settings.h"

#include "core/eventHandler.h"
#include "core/render.h"

int main() {
    setbuf(stdout, 0);

    if (!al_init())
        error("Can't init allegro5");

    al_set_app_name(APP_NAME);

    char *currentDir = al_get_current_directory();
    Config *cfg = cfg_init(currentDir);
    al_free(currentDir);

    ALLEGRO_DISPLAY *display = al_create_display(cfg->display.width, cfg->display.height);
    if (!display)
        error("Can't create display");

    debug("Run event handler");
    run_event_handler(display);

    EventInfo eventInfo;
    eventInfo.isRun = true;
    ALLEGRO_THREAD *renderThread = al_create_thread(run_render, &eventInfo);
    al_start_thread(renderThread);
    al_join_thread(renderThread, NULL);
    al_destroy_thread(renderThread);
    debug("End event handler");


    al_destroy_display(display);
    cfg_free();

    al_uninstall_system();
    return 0;
}
