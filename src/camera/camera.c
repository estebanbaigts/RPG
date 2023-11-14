/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** camera
*/

#include "camera.h"
#include "game.h"

void init_camera(camera_t *camera)
{
    (*camera).x = -300;
    (*camera).y = -300;
    (*camera).lock = sfTrue;
}

void moving(camera_t *camera, player_t *player)
{
    if ((*camera).lock) {
        (*camera).x = (*player).x;
        (*camera).y = (*player).y;
    }
}

void update_camera(game_t *game)
{
    moving(&game->camera, &game->player);
}
