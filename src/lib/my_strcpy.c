/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    if (!src)
        return 0;

    for (; src[i]; i++)
        dest[i] = src[i];

    dest[i] = 0;
    return dest;
}
