//
// Created by Shon on 01.07.2024.
//

#ifndef BLASTEROIDS_CONFIG_H
#define BLASTEROIDS_CONFIG_H

#include <allegro5/allegro.h>

typedef struct {
    unsigned int width;
    unsigned int height;
} DISPLAY;

typedef struct {
    DISPLAY display;
} CONFIG;

static void read_cfg();

static int option(const char *section, const char *key, int def);

CONFIG *get_cfg();

CONFIG *cfg_init(const char *dirPath);

void set_value();

#endif //BLASTEROIDS_CONFIG_H
