/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** update_npc
*/

#include "game.h"

static void move_npc(game_t *game, npc_t *npc)
{
    sfVector2f pos = sfSprite_getPosition(game->map.sprite);
    pos.x += (*npc).x;
    pos.y += (*npc).y;
    (*npc).box.left = pos.x;
    (*npc).box.top = pos.y;
    sfSprite_setPosition((*npc).sprite, pos);
    sfSprite_setPosition(game->npc.sprite,
    (sfVector2f){pos.x + 20, pos.y - 70});
    if (sfKeyboard_isKeyPressed(sfKeyE) && !game->text.show) {
        game->text.id = 0;
        game->text.show = sfTrue;
    }
    if (game->text.show)
        (*npc).dialogue(&game->text);
}

static void player_touch_test(game_t *game, npc_t *npc)
{
    if (sfFloatRect_intersects(&game->player.hitbox, &npc->box, NULL))
        game->npc.show = sfTrue;
    else
        game->npc.show = sfFalse;
}

void update_npc(game_t *game)
{
    for (int i = 0; i < 2; i++) {
        if (game->map.stat == game->npc.npc[i].map) {
            move_npc(game, &game->npc.npc[i]);
            player_touch_test(game, &game->npc.npc[i]);
        }
    }
}