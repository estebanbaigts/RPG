/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** enemies
*/

#include "game.h"

static void set_texture(game_t *game)
{
    for (int i = 0; enemie_name[i]; i++) {
        sfTexture *texture = load_texture("./img/enemie/", enemie_name[i]);
        game->enemies.texture[i] = texture;
    }
}

void init_enemies(game_t *game)
{
    set_texture(game);
    game->enemies.ghoul_list = malloc(sizeof(ghoul_list_t));
    game->enemies.ghoul_list = NULL;
    int x;
    int y;
    for (int i = 0; enemies_pos_list[i].spawn_x; i++) {
        int x = enemies_pos_list[i].spawn_x;
        int y = enemies_pos_list[i].spawn_x;
        ghoul_append(game, &game->enemies.ghoul_list, enemies_pos_list[i]);
    }
}

void update_enemies(game_t *game)
{
    update_ghoul_list(game, &game->enemies.ghoul_list);
}

void render_enemies(game_t *game)
{
    render_ghoul_list(game, game->enemies.ghoul_list);
}
