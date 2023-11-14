/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** player_render
*/

#include "game.h"

static void set_texture(game_t *game)
{
    if (game->player.stat == IDLE)
        animated_player_idle(game);

    if (game->player.stat == WALK)
        animated_player(game, 4, 0.2);

    if (game->player.stat == ATTACK)
        animated_player(game, 4, 0.1);

}

void render_player(game_t *game)
{
    player_t player = game->player;
    set_texture(game);
    sfSprite_setTexture(player.sprite, player.texture[player.stat], sfFalse);
    sfRenderWindow_drawSprite(game->window, player.sprite, NULL);
}
