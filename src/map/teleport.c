/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** change_map
*/

#include "game.h"
#include "map.h"

static void verif_box_collision(game_t *game, int i)
{
    player_t *player = &game->player;
    map_t *map = &game->map;
    sfFloatRect door_rect = *map_tp_list[i].rect;
    sfVector2f map_pos = sfSprite_getPosition((*map).sprite);
    door_rect.left = door_rect.left + map_pos.x;
    door_rect.top = door_rect.top + map_pos.y;
    if (sfFloatRect_intersects(&(*player).hitbox, &door_rect, NULL)) {
        (*map).stat = map_tp_list[i].where;
        (*player).x = map_tp_list[i].tp_x;
        (*player).y = map_tp_list[i].tp_y;
    }
}

void can_teleport_player(game_t *game)
{
    for (int i = 0; map_tp_list[i].rect; i++) {
        if (map_tp_list[i].map == game->map.stat)
            verif_box_collision(game, i);
    }
}
