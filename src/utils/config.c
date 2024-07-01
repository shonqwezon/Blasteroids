//
// Created by Shon on 01.07.2024.
//

#include "config.h"

#include <string.h>
#include <stdio.h>

#include "settings.h"
#include "logging.h"

typedef struct ALLEGRO_CONFIG ALLEGRO_CONFIG;

static ALLEGRO_CONFIG *cfg;
static CONFIG *data;

CONFIG *cfg_init(const char *dirPath) {
    if (data) return data;

    char cfgPath[strlen(dirPath) + 1 + strlen(CONFIG_NAME) + 1];
    sprintf_s(cfgPath, sizeof(cfgPath), "%s\\%s", dirPath, CONFIG_NAME);
    debug("Config path: %s", cfgPath);

    cfg = al_load_config_file(cfgPath);

    data = malloc(sizeof(CONFIG));
    if (!cfg) {
        debug("Initiating config file");
        cfg = al_create_config();
        read_cfg();
        al_save_config_file(CONFIG_NAME, cfg);
    }
    return data;
}

CONFIG *get_cfg() {
    if (!data)
        error("Config hasn't been initialized");
    return data;
}

void read_cfg() {
    data->display.width = option("system", "width", 1600);
    data->display.height = option("system", "height", 900);
}

int option(const char *section, const char *key, int def) {
    char const *value;
    value = al_get_config_value(cfg, section, key);

    if (value)
        def = strtol(value, NULL, 0);
    else {
        char str[256];
        sprintf(str, "%d", def);
        al_set_config_value(cfg, section, key, str);
    }
    return def;
}
