/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** player_animation
*/

#include "game.h"

void animated_player_idle(game_t *game)
{
    player_t player = game->player;
    sfIntRect rect = {0, player.facing * 33, 24, 33};
    sfSprite_setTextureRect(player.sprite, rect);
}

void animated_player(game_t *game, int frame_nbr, float delay)
{
    player_t player = game->player;
    sfClock *clock = game->clock[P_ANIMATION];
    sfTime time = sfClock_getElapsedTime(clock);
    int *frame = &game->player.frame;
    if (sfTime_asSeconds(time) > delay) {
        if (*frame == (24 * (frame_nbr - 1))) {
            *frame = 0;
        } else {
            *frame += 24;
        }
        sfClock_restart(clock);
    }
    sfIntRect rect = {*frame, player.facing * 33, 24, 33};
    sfSprite_setTextureRect(player.sprite, rect);
}
