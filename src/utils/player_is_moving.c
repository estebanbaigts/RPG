/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** player_is_moving
*/

#include "game.h"

sfBool player_is_moving(game_t const *game)
{
    for (int i = 0; i < 4; i++) {
        if (game->player.move[i])
            return sfTrue;
    }
    return sfFalse;
}
