//
// Created by Shon on 01.07.2024.
//

#ifndef BLASTEROIDS_CONFIG_H
#define BLASTEROIDS_CONFIG_H

#include <allegro5/allegro.h>

typedef struct {
    unsigned int width;
    unsigned int height;
} Display;

typedef struct {
    Display display;
    unsigned int tps;
} Config;

static void read_cfg();
static void write_cfg();

static int option(const char *section, const char *key, int def, bool fWrite);

Config *get_cfg();

Config *cfg_init(const char *dirPath);

void cfg_free();

#endif //BLASTEROIDS_CONFIG_H
