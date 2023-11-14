/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** my_strdup
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char *my_strcdup(char const *src, char c)
{
    int i = 0;
    int n = 0;
    if (!src)
        return 0;

    for (; src[n] && src[n] != c; n++);
    char *str = malloc(n);
    if (!str)
        return 0;

    for (; i < n && src[i]; i++) {
        str[i] = src[i];
    }

    str[i] = 0;
    return str;
}

char *my_strndup(char const *src, int n)
{
    int i = 0;
    if (!src)
        return 0;

    char *str = malloc(n);
    if (!str)
        return 0;

    for (; i < n && src[i]; i++)
        str[i] = src[i];

    str[i] = 0;
    return str;
}
