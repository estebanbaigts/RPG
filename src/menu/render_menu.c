/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** render_menu
*/

#include "game.h"

void render_menu(game_t *game)
{
    sfColor color;
    sfRenderWindow_drawSprite(game->window, game->menu.sprite,NULL);
    for (int i = 0; button_name[i]; i++) {
        button_t button = game->menu.button[i];
        color = (sfColor){255, 255, 255, 255};
        if (game->menu.button[i].stat == HOVER)
            color = (sfColor){230, 230, 230, 255};
        sfSprite_setColor(game->menu.button[i].sprite, color);
        sfRenderWindow_drawSprite(game->window, button.sprite, NULL);
    }
}