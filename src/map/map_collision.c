/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** map_collision
*/

#include "game.h"

static void set_image(map_t *map)
{
    for (int i = 1; maps_name[i]; i++) {
        char *str = get_path("./img/wall/", maps_name[i], ".png");
        (*map).wall[i] = sfImage_createFromFile(str);
        free(str);
    }
}

void init_wall(game_t *game)
{
    set_image(&game->map);
}
