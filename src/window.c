/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** window
*/

#include "global.h"
#include "game.h"

void init_window(game_t *game)
{
    sfVideoMode mode = {SCREEN_WIDTH * RATIO, SCREEN_HEIGHT * RATIO, 32};
    sfUint32 style = sfResize | sfClose;
    game->window = sfRenderWindow_create(mode, "My Rpg", style, NULL);
    sfFloatRect rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    sfView *view = sfView_createFromRect(rect);
    sfRenderWindow_setView(game->window, view);
}
