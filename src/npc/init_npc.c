/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** init_npc
*/

#include "game.h"

static void set_texture(game_t *game)
{
    game->npc.npc_texture[pancarte] = load_texture("./img/npc/", "pancarte");
    game->npc.bubble_texture = load_texture("./img/npc/", "bubble");
}

void init_npc(game_t *game)
{
    set_texture(game);
    init_pancarte(game, &game->npc.npc[pancarte]);
    game->npc.sprite = sfSprite_create();
    sfSprite_setTexture(game->npc.sprite, game->npc.bubble_texture, sfFalse);
    sfSprite_setScale(game->npc.sprite, (sfVector2f){2, 2});
    game->npc.show = sfFalse;
}
