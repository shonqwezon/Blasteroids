//
// Created by Shon on 01.07.2024.
//

#include "logging.h"

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "settings.h"

void debug(char const *format, ...) {
    char str[OUTPUT_BUFF_SIZE];

    va_list args;
    va_start(args, format);
    vsnprintf(str, sizeof(str), format, args);
    va_end(args);

    fprintf(stdout, "DEBUG: %s\n", str);
}

void error(char const *format, ...) {
    char str[OUTPUT_BUFF_SIZE];

    va_list args;
    va_start(args, format);
    vsnprintf(str, sizeof(str), format, args);
    va_end(args);

    fprintf(stderr, "ERROR: %s - %s\n", str, strerror(errno));
    exit(1);
}
