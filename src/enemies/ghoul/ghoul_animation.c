/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** ghoul_animation
*/

#include "game.h"

void set_animation_ghoul(game_t *game, ghoul_t *ghoul, int nbr)
{
    sfSprite *sprite = (*ghoul).sprite;
    sfTime time = sfClock_getElapsedTime((*ghoul).clock[P_ANIMATION]);
    if (sfTime_asSeconds(time) > 0.2) {
        if ((*ghoul).frame == (32 * (nbr - 1))) {
            (*ghoul).frame = 0;
        } else {
            (*ghoul).frame += 32;
        }
        sfClock_restart((*ghoul).clock[P_ANIMATION]);
    }
    sfIntRect rect = {(*ghoul).frame, (*ghoul).stat * 32, 32, 32};
    sfSprite_setTextureRect(sprite, rect);
}
