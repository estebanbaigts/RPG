/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** update
*/

#include "game.h"

static void update_asset(game_t *game)
{
    update_camera(game);
    if (!game->player.lock)
        update_player(game);
    update_map(game);
    update_enemies(game);
    update_npc(game);
}

void update(game_t *game)
{
    if (game->menu.play) {
        if (!game->menu.pause)
            update_asset(game);
        pause_update(game);;
    } else {
        update_menu(game);
    }
}
