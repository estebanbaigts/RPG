/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** ghoul_hit
*/

#include "game.h"

static void get_damage(game_t *game, ghoul_t *ghoul)
{
    if (!ghoul->invincible)
        (*ghoul).hp -= game->stat.damage;
}

void ghoul_hit_test(game_t *game, ghoul_t *ghoul)
{
    if (sfFloatRect_intersects(&game->player.hitbox, &(*ghoul).hitbox, NULL)) {
        if (game->player.stat == ATTACK) {
            sfSprite_setColor((*ghoul).sprite, (sfColor){255, 0, 0, 255});
            get_damage(game, ghoul);
            (*ghoul).invincible = sfTrue;
        } else {
            sfSprite_setColor((*ghoul).sprite, (sfColor){255, 255, 255, 255});
            (*ghoul).invincible = sfFalse;
        }
    } else {
        sfSprite_setColor((*ghoul).sprite, (sfColor){255, 255, 255, 255});
    }
}
