/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** init_player
*/

#include "global.h"
#include "player.h"
#include "game.h"

static void set_texture(game_t *game)
{
    if (!game)
        return;

    sfTexture *texture = load_player_texture("idle");
    game->player.texture[IDLE] = texture;
    texture = load_player_texture("walk");
    game->player.texture[WALK] = texture;
    texture = load_player_texture("attack");
    game->player.texture[ATTACK] = texture;
    sfSprite_setTexture(game->player.sprite, game->player.texture[IDLE],
    sfFalse);
    sfIntRect rect = {0, 33 * DOWN, 24, 33};
    sfSprite_setTextureRect(game->player.sprite, rect);
}

void init_player(game_t *game)
{
    sfSprite *sprite = sfSprite_create();
    if (!sprite || !game)
        return;

    sfVector2f pos;
    pos.x = SCREEN_CX - PLAYER_WIDTH;
    pos.y = SCREEN_CY - PLAYER_HEIGHT;
    sfSprite_setPosition(sprite, pos);
    game->player.sprite = sprite;
    sfSprite_setScale(game->player.sprite, (sfVector2f){2, 2});
    game->player.x = -337;
    game->player.y = -384;
    sfFloatRect rect = {pos.x, pos.y, PLAYER_HEIGHT, PLAYER_WIDTH};
    game->player.hitbox = rect;
    game->player.facing = DOWN;
    game->player.stat = IDLE;
    game->player.frame = 0;
    game->player.lock = sfFalse;
    set_texture(game);
}
