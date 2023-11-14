/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** pancarte
*/

#include "game.h"

void pancarte_dialogue(text_t *text)
{
    read_text(text, "./txt/pancarte/message1", 0);
    if ((*text).id >= 2)
        (*text).show = sfFalse;
}

void init_pancarte(game_t *game, npc_t *npc)
{
    (*npc).x = 470;
    (*npc).y = 230;
    (*npc).map = grotte;
    sfFloatRect rect = {480, 260, 100, 95};
    (*npc).box = rect;
    (*npc).sprite = sfSprite_create();
    sfSprite_setTexture((*npc).sprite, game->npc.npc_texture[pancarte],
    sfFalse);
    sfSprite_setScale((*npc).sprite, (sfVector2f){1, 1});
    (*npc).dialogue = &pancarte_dialogue;
}
