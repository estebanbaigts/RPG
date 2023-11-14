/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** player_update
*/

#include "game.h"

static void update_player_facing(game_t *game)
{
    for (int face = 0; face < 4; face++) {
        if (game->player.move[face]) {
            game->player.facing = face;
            break;
        }
    }
}

static void change_player_stat(game_t *game)
{
    if (player_is_moving(game)) {
        game->player.stat = WALK;
    } else {
        game->player.stat = IDLE;
    }
}

static void try_move(game_t *game)
{
    player_t *player = &game->player;
    sfVector2f next_pos = {0, 0};

    if ((*player).move[UP]) next_pos.y += PLAYER_SPEED;
    if ((*player).move[DOWN]) next_pos.y -= PLAYER_SPEED;
    if ((*player).move[RIGHT]) next_pos.x -= PLAYER_SPEED;
    if ((*player).move[LEFT]) next_pos.x += PLAYER_SPEED;

    if (!collide_with_wall(game, next_pos)) {
        (*player).x += next_pos.x;
        (*player).y += next_pos.y;
    }
}

static void move_update(game_t *game)
{
    try_move(game);
    player_t *player = &game->player;
    update_player_facing(game);
    sfVector2f pos;
    if (!game->camera.lock) {
        pos.x = game->camera.x - (*player).x + (SCREEN_CX - PLAYER_WIDTH);
        pos.y = game->camera.y - (*player).y + (SCREEN_CY - PLAYER_HEIGHT);
    } else {
        pos.x = (SCREEN_CX - PLAYER_WIDTH);
        pos.y = (SCREEN_CY - PLAYER_HEIGHT);
    }
    sfSprite_setPosition((*player).sprite, pos);
    (*player).hitbox.left = pos.x;
    (*player).hitbox.top = pos.y;

    change_player_stat(game);
}

void update_player(game_t *game)
{
    if (game->player.stat != ATTACK)
        move_update(game);

    if (game->player.stat == ATTACK) {
        sfClock *clock = game->clock[ATTACK_DELAY];
        sfTime time = sfClock_getElapsedTime(clock);
        if (sfTime_asSeconds(time) > 0.4) {
            game->player.stat = IDLE;
            game->player.frame = 0;
        }
    }

}
