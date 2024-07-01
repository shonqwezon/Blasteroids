//
// Created by Shon on 01.07.2024.
//

#include "common.h"

#include <string.h>
#include <stdlib.h>

char *concat(const char *str1, const char *str2) {
    char *res = malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(res, str1);
    strcat(res, str2);
    return res;
}
