/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** layer
*/

#include "game.h"

static void set_texture(layer_t *layer)
{
    for (int i = 1; maps_name[i]; i++) {
        (*layer).texture[i] = load_texture("./img/3d/", maps_name[i]);
    }
}

void update_layer(game_t *game)
{
    sfSprite *sprite = game->map.layer.sprite;
    sfVector2f pos = sfSprite_getPosition(game->map.sprite);
    sfSprite_setPosition(sprite, pos);
}

void render_layer(game_t *game)
{
    layer_t layer = game->map.layer;
    int stat = game->map.stat;
    sfSprite_setTexture(layer.sprite, layer.texture[stat], sfTrue);
    sfRenderWindow_drawSprite(game->window, layer.sprite, NULL);
}

void init_layer(game_t *game)
{
    layer_t *layer = &game->map.layer;
    (*layer).sprite = sfSprite_create();
    set_texture(layer);
}
