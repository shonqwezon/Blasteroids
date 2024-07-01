#include <allegro5/allegro.h>

#include "utils/config.h"
#include "utils/logging.h"
#include "utils/settings.h"

#include "core/eventHandler.h"

int main() {
    if(!al_init()) {
        error("Can't init allegro5");
    }
    al_set_app_name(APP_NAME);

    char *currentDir = al_get_current_directory();
    CONFIG *cfg = cfg_init(currentDir);
    debug("%d", cfg->display.height);
    al_free(currentDir);

//    ALLEGRO_DISPLAY * display = al_create_display(1600, 900);
//    if(!display) {
//        printf("Error!\n");
//    }
//    run_event_handler();
//    al_uninstall_system();

    cfg_free();
    return 0;
}
