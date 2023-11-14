/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** map
*/

#include "game.h"
#include "map.h"

static void set_texture(game_t *game)
{
    for (int i = 1; maps_name[i]; i++) {
        char *path = get_path("./img/map/", maps_name[i], ".png");
        game->map.texture[i] = sfTexture_createFromFile(path, NULL);
        free(path);
    }
}

void update_map(game_t *game)
{
    can_teleport_player(game);
    map_t *map = &game->map;
    sfVector2f pos;
    pos.x = (game->camera.x + (int)SCREEN_CX);
    pos.y = (game->camera.y + (int)SCREEN_CY);
    sfSprite_setPosition((*map).sprite, pos);
    sfSprite_setTexture((*map).sprite, (*map).texture[(*map).stat], sfTrue);
    update_layer(game);
}

void render_map(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->map.sprite, NULL);
}

void init_map(game_t *game)
{
    int stat = grotte;
    set_texture(game);
    game->map.sprite = sfSprite_create();
    sfSprite_setTexture(game->map.sprite, game->map.texture[stat] ,sfTrue);
    game->map.stat = stat;
    init_wall(game);
    init_layer(game);
}
