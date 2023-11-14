/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** load_texture
*/

#include "game.h"

sfTexture *load_player_texture(char const *name)
{
    sfTexture *texture;
    if (!name)
        return NULL;

    char *path = get_path("./img/player/", name, ".png");
    texture = sfTexture_createFromFile(path, NULL);
    free(path);
    if (!texture)
        return NULL;

    return texture;
}

sfTexture *load_texture(char const *path, char const *name)
{
    sfTexture *texture;
    if (!name)
        return NULL;

    char *str = get_path(path, name, ".png");
    texture = sfTexture_createFromFile(str, NULL);
    free(str);
    if (!texture)
        return NULL;

    return texture;
}
