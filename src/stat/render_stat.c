/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** render_stat
*/

#include "game.h"

static void render_hp(game_t *game, stat_t *stat)
{
    sfIntRect rect = {0, 0, 16, 16};
    sfSprite *sprite;
    for (int i = 0; i < (*stat).max_hp; i++) {
        sprite = (*stat).hp_sprite[i].sprite;
        if ((*stat).hp_sprite[i].id > (*stat).hp - 1) {
            rect.left = 16;
        } else {
            rect.left = 0;
        }
        sfSprite_setTextureRect(sprite, rect);
        sfRenderWindow_drawSprite(game->window, sprite , NULL);
    }
}

void render_stat(game_t *game)
{
    stat_t *stat = &game->stat;
    render_hp(game, stat);
}
