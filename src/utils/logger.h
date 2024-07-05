//
// Created by Shon on 01.07.2024.
//

#ifndef BLASTEROIDS_LOGGER_H
#define BLASTEROIDS_LOGGER_H

typedef enum {
    PROC,
    ABORT
} ErrorMode;

void error(ErrorMode errorMode, char const *format, ...);

void debug(char const *format, ...);

#endif //BLASTEROIDS_LOGGER_H
