/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** texture_path
*/

#include "lib.h"

#include <stdlib.h>

char *get_path(char const *path, char const *name, char const *format)
{
    int total_len = 0;
    total_len += my_strlen(path);
    total_len += my_strlen(name);
    total_len += my_strlen(format);
    char *str = malloc(total_len + 2);
    if (!str)
        return 0;

    str = my_strcpy(str, path);
    str = my_strcat(str, name);
    str = my_strcat(str, format);
    return str;
}
