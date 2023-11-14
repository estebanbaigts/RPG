/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** button_menu
*/

#include "game.h"

static void update_button(game_t *game, button_t *button)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);
    pos.x = pos.x / RATIO;
    pos.y = pos.y / RATIO;
    if (sfFloatRect_contains(&(*button).rect, pos.x, pos.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            button->stat = PRESSED;
        } else {
            button->stat = HOVER;
        }
    } else {
        button->stat = UNPRESS;
    }
}

static void button_event(game_t *game, button_t *button)
{
    if ((*button).type == PLAY && (*button).stat == PRESSED)
        game->menu.play = sfTrue;
}

void pause_update(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && !game->menu.one_tap) {
        if (game->menu.pause == sfTrue) {
            game->menu.pause = sfFalse;
        } else {
            game->menu.pause = sfTrue;
        }
        game->menu.one_tap = sfTrue;
    }

    if (!sfKeyboard_isKeyPressed(sfKeyEscape))
        game->menu.one_tap = sfFalse;
}

void update_menu(game_t *game)
{
    if (!game->menu.play) {
        for (int i = 0; button_name[i]; i++) {
            update_button(game, &game->menu.button[i]);
            button_event(game, &game->menu.button[i]);
        }
    }
}
