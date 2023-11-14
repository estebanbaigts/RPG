/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** event
*/

#include "game.h"

void sfml_event(game_t *game)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        camera_t *camera = &game->camera;
        if (sfKeyboard_isKeyPressed(sfKeyA))
            (*camera).lock = sfFalse;
        if (sfKeyboard_isKeyPressed(sfKeyZ))
            (*camera).lock = sfTrue;
        if (!game->player.lock)
            player_event(game);
        text_event(game);
    }
}
