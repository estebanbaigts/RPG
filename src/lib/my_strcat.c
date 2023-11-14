/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** my_strcat
*/

#include "lib.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int len = my_strlen(dest);
    for (; src[i]; i++)
        dest[len + i] = src[i];

    dest[i + len] = 0;
    return dest;
}
