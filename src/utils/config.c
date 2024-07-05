//
// Created by Shon on 01.07.2024.
//

#include "config.h"

#include <string.h>
#include <stdio.h>

#include "settings.h"
#include "logger.h"

static ALLEGRO_CONFIG *cfg;
static Config *data;

Config *cfg_init(const char *dirPath) {
    if (data) return data;

    char cfgPath[strlen(dirPath) + 1 + strlen(CONFIG_NAME) + 1];
    sprintf_s(cfgPath, sizeof(cfgPath), "%s\\%s", dirPath, CONFIG_NAME);
    debug("Config path: %s", cfgPath);

    cfg = al_load_config_file(cfgPath);

    data = malloc(sizeof(Config));
    if (!cfg) {
        debug("Initiating config file");
        cfg = al_create_config();
    }
    read_cfg();
    return data;
}

Config *get_cfg() {
    if (!data)
        error(ABORT, "Config hasn't been initialized");
    return data;
}

void read_cfg() {
    data->display.width = option("system", "width", 1600, false);
    data->display.height = option("system", "height", 900, false);
    data->tps = option("game", "tps", 25, false);
    al_save_config_file(CONFIG_NAME, cfg);
}

void write_cfg() {
    option("system", "width", data->display.width, true);
    option("system", "height", data->display.height, true);
    option("game", "tps", data->tps, true);
    al_save_config_file(CONFIG_NAME, cfg);
}

int option(const char *section, const char *key, int def, bool fWrite) {
    char const *value;
    value = al_get_config_value(cfg, section, key);

    if (value && !fWrite)
        def = strtol(value, NULL, 0);
    else {
        char str[256];
        sprintf(str, "%d", def);
        al_set_config_value(cfg, section, key, str);
    }
    return def;
}

void cfg_free() {
    write_cfg();
    free(data);
    al_destroy_config(cfg);
}
