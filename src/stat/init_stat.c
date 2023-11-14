/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** init_stat
*/

#include "game.h"

static void init_hp(game_t *game, hp_sprite_t *hp, int i)
{
    (*hp).id = i;
    (*hp).sprite = sfSprite_create();
    sfSprite_setTexture((*hp).sprite, game->stat.texture[HP], sfFalse);
    sfVector2f pos = {10 + 32.0 * (*hp).id, SCREEN_HEIGHT - 50};
    sfSprite_setPosition((*hp).sprite, pos);
    sfIntRect rect = {0, 0, 16, 16};
    sfSprite_setTextureRect((*hp).sprite, rect);
    sfSprite_setScale((*hp).sprite, (sfVector2f){2, 2});
}

static void set_texture(game_t *game)
{
    stat_t *stat = &game->stat;
    char *path = "./img/stat/";
    stat->texture[HP] = load_texture(path, "hp");
}

void init_stat(game_t *game)
{
    if (!game)
        return;

    game->stat.hp = 5;
    game->stat.max_hp = 5;
    game->stat.damage = 5;
    set_texture(game);
    for (int i = 0; i < 10; i++) {
        init_hp(game, &game->stat.hp_sprite[i], i);
    }
}
