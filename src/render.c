/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** render
*/

#include "game.h"

static void render_asset(game_t *game)
{
    render_map(game);
    render_enemies(game);
    render_npc(game);
    render_player(game);
    render_layer(game);
    render_stat(game);
    render_text(game);
}

void render(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    if (game->menu.play) {
        render_asset(game);
    } else {
        render_menu(game);
    }
    sfRenderWindow_display(game->window);
}
