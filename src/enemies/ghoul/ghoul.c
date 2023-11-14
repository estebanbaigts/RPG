/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** enemie
*/

#include "game.h"
#include "ghoul.h"

static void init_ghoul_clock(game_t *game, ghoul_list_t *list)
{
    for (int i = 0; i < 2; i++) {
        list->element.clock[i] = sfClock_create();
    }
}

void init_ghoul(game_t *game, ghoul_list_t *list, enemies_pos_t pos)
{
    if (!list || !game)
        return;
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = game->enemies.texture[ghoul];
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setScale(sprite, (sfVector2f){2, 2});
    sfSprite_setTextureRect(sprite, (sfIntRect){0, 0, 32, 32});
    sfFloatRect rect = {0, 0, 64, 64};
    list->element.hitbox = rect;
    list->element.spawn_x = pos.spawn_x; list->element.spawn_y = pos.spawn_x;
    list->element.x = 0; list->element.y = 0;
    list->element.sprite = sprite;
    list->element.alive = sfTrue;
    init_ghoul_clock(game, list);
    list->element.stat = G_IDLE;
    list->element.frame = 0;
    list->element.hp = 10;
    list->element.invincible = sfFalse;
    list->element.map = pos.map;
}

void update_ghoul(game_t *game, ghoul_list_t *list)
{
    player_t player = game->player;
    sfVector2f pos = sfSprite_getPosition(game->map.sprite);
    pos.x += list->element.spawn_x + list->element.x;
    pos.y += list->element.spawn_y + list->element.y;
    list->element.hitbox.left = pos.x;
    list->element.hitbox.top = pos.y;
    sfSprite_setPosition(list->element.sprite, pos);
    ghoul_hit_test(game, &list->element);
    if (list->element.hp <= 0) {
        game->stat.max_hp += 1;
        game->stat.hp += 1;
        game->stat.damage += 1;
        list->element.alive = sfFalse;
    }
}

void render_ghoul(game_t *game, ghoul_list_t *list)
{
    sfSprite *sprite = list->element.sprite;
    if (!game->menu.pause) {
        if (list->element.stat == G_IDLE)
            set_animation_ghoul(game, &list->element, 4);
        if (list->element.stat == G_WALK)
            set_animation_ghoul(game, &list->element, 8);
        if (list->element.stat == G_ATTACK)
            set_animation_ghoul(game, &list->element, 6);
        if (list->element.stat == G_DEATH)
            set_animation_ghoul(game, &list->element, 6);
    }

    sfRenderWindow_drawSprite(game->window, sprite, NULL);
}