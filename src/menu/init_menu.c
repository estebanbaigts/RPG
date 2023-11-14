/*
** EPITECH PROJECT, 2023
** menu
** File description:
** init menu
*/

#include "game.h"

static void init_button(game_t *game, button_t *button, int i)
{
    (*button).sprite = sfSprite_create();
    (*button).texture = load_texture("img/menu/", button_name[i]);
    (*button).type = button_list[i].stat;
    (*button).stat = UNPRESS;
    (*button).rect = *button_list[i].rect;
    sfSprite_setTexture((*button).sprite, (*button).texture, sfTrue);
    sfVector2f pos;
    pos.x = (*button).rect.left;
    pos.y = (*button).rect.top;
    sfSprite_setPosition((*button).sprite, pos);
    sfSprite_setScale((*button).sprite, (sfVector2f){5, 5});
}

void init_menu(game_t *game)
{
    for (int i = 0; button_name[i]; i++) {
        init_button(game, &game->menu.button[i], i);
    }
    game->menu.pause = sfFalse;
    game->menu.play = sfFalse;
    game->menu.one_tap = sfFalse;
    game->menu.sprite = sfSprite_create();
    game->menu.texture = load_texture("./img/menu/", "menu");
    sfSprite_setTexture(game->menu.sprite, game->menu.texture, sfFalse);
    sfSprite_setPosition(game->menu.sprite, (sfVector2f){-100, 0});
    sfSprite_setScale(game->menu.sprite, (sfVector2f){0.465, 0.465});
}

