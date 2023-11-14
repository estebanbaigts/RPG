/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** player_collision
*/

#include "game.h"

static sfBool is_collide(game_t *game, int x, int y, sfVector2f next)
{
    map_t map = game->map;
    sfVector2f map_pos = sfSprite_getPosition(map.sprite);
    sfVector2f pos;
    pos.x = (map_pos.x * -1) + (SCREEN_CX - PLAYER_CX) - next.x + x;
    pos.y = (map_pos.y * -1) + (SCREEN_CY) - next.y + y;
    sfImage *img = map.wall[map.stat];
    sfColor color = sfImage_getPixel(img, (int)pos.x, (int)pos.y);
    if (color.r == 0 && color.b == 0 && color.g == 0) {
        return sfTrue;
    }

    return sfFalse;
}

static sfBool collide_in_y(game_t *game, int x, sfVector2f next)
{
    for (int y = 0; y < PLAYER_HEIGHT; y++) {
        if (is_collide(game, x, y, next)) {
            return sfTrue;
        }
    }
    return sfFalse;
}

sfBool collide_with_wall(game_t *game, sfVector2f next)
{
    for (int x = 0; x < PLAYER_WIDTH; x++) {
        if (collide_in_y(game, x, next)) {
            return sfTrue;
        }
    }
    return sfFalse;
}
