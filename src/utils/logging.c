//
// Created by Shon on 01.07.2024.
//

#include "logging.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <allegro5/allegro.h>

void debug(const char *msg) {
    fprintf(stdout, "DEBUG: %s\n", msg);
}

void error(const char *msg) {
    fprintf(stderr, "ERROR: %s - %s - %s\n", msg, strerror(errno), strerror(al_get_errno()));
    exit(1);
}
