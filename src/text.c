/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** $
*/

#include "game.h"

void text_event(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyX) && !game->text.key_x) {
        game->text.id += 1;
    }

    if (sfKeyboard_isKeyPressed(sfKeyX))
        game->text.key_x = sfTrue;
    if (!sfKeyboard_isKeyPressed(sfKeyX))
        game->text.key_x = sfFalse;

}

void render_text(game_t *game)
{
    if (game->text.show) {
        sfRenderWindow_drawSprite(game->window, game->text.sprite, NULL);
        sfRenderWindow_drawText(game->window, game->text.text, NULL);
    }
}

static void init_sprite(game_t *game)
{
    game->text.sprite = sfSprite_create();
    char *path = get_path("./img/text/", "plaque", ".png");
    game->text.texture = sfTexture_createFromFile(path, NULL);
    free(path);
    sfSprite_setTexture(game->text.sprite, game->text.texture, sfFalse);
    sfVector2f pos = {0, 350};
    sfSprite_setPosition(game->text.sprite, pos);
}

void init_text(game_t *game)
{
    game->text.font = sfFont_createFromFile("./font/freecamv2.ttf");
    game->text.text = sfText_create();
    sfText_setFont(game->text.text, game->text.font);
    sfVector2f pos = {50, 400};
    sfText_setPosition(game->text.text, pos);
    game->text.show = sfFalse;
    sfText_setCharacterSize(game->text.text, 10);
    sfText_setLineSpacing(game->text.text, 2);
    sfText_setColor(game->text.text, (sfColor){255, 255, 255, 255});
    sfText_setOutlineColor(game->text.text, (sfColor){0, 0, 0, 255});
    sfText_setOutlineThickness(game->text.text, 1.0f);
    game->text.id = 0;
    init_sprite(game);
}
