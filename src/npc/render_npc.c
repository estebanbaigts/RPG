/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** render_npc
*/

#include "game.h"

static void draw_npc(game_t *game, npc_t *npc)
{
    sfRenderWindow_drawSprite(game->window, (*npc).sprite, NULL);
}

void render_npc(game_t *game)
{
    for (int i = 0; i < 2; i++) {
        if (game->map.stat == game->npc.npc[i].map) {
            draw_npc(game, &game->npc.npc[i]);
        }
    }
    if (game->npc.show && !game->text.show)
        sfRenderWindow_drawSprite(game->window, game->npc.sprite, NULL);
}