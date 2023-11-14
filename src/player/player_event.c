/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** player_event
*/

#include "game.h"
#include "player.h"

static void player_move_unpress(player_t *player)
{
    if (!sfKeyboard_isKeyPressed(sfKeyUp))
        (*player).move[UP] = sfFalse;
    if (!sfKeyboard_isKeyPressed(sfKeyDown))
        (*player).move[DOWN] = sfFalse;
    if (!sfKeyboard_isKeyPressed(sfKeyRight))
        (*player).move[RIGHT] = sfFalse;
    if (!sfKeyboard_isKeyPressed(sfKeyLeft))
        (*player).move[LEFT] = sfFalse;
}

static void player_move_press(player_t *player, sound_t *sounds)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        (*player).move[UP] = sfTrue;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        (*player).move[DOWN] = sfTrue;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        (*player).move[RIGHT] = sfTrue;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        (*player).move[LEFT] = sfTrue;
    }
}

void player_event(game_t *game)
{
    player_move_press(&game->player, &game->sounds);
    player_move_unpress(&game->player);

    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        sfClock_restart(game->clock[ATTACK_DELAY]);
        game->player.stat = ATTACK;
    }
}
