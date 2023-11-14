/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** clock
*/

#include "game.h"

void init_clocks(game_t *game)
{
    for (int i = 0; i < 3; i++) {
        game->clock[i] = sfClock_create();
    }
}
