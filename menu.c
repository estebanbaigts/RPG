/*
** EPITECH PROJECT, 2023
** menu
** File description:
** init menu
*/

#include <SFML/Graphics.h>

void createplaybutton(sfRectangleShape *playButton)
{
    sfVector2f playButtonSize = {200.f, 50.f};
    sfRectangleShape_setSize(playButton, playButtonSize);
    sfVector2f playButtonPos = {300.f, 200.f};
    sfRectangleShape_setPosition(playButton, playButtonPos);
}

void createsettingsbutton(sfRectangleShape *settingsButton)
{
    sfVector2f settingsButtonSize = {200.f, 50.f};
    sfRectangleShape_setSize(settingsButton, settingsButtonSize);
    sfVector2f settingsButtonPos = {300.f, 300.f};
    sfRectangleShape_setPosition(settingsButton, settingsButtonPos);
}

void createtext(sfText *text)
{
    sfFont *font = sfFont_createFromFile("arial.ttf");
    sfText_setString(text, "Bonjour");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 24);
    sfVector2f textPos = {350.f, 350.f};
    sfText_setPosition(text, textPos);
}

void drawbutton(sfRenderWindow *window, sfRectangleShape *button)
{
    sfRenderWindow_drawRectangleShape(window, button, NULL);
}

void handleclick(sfRenderWindow *window, sfRectangleShape *button, sfText *text)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sfVector2i mousePos = sfMouse_getPositionRenderWindow(window);
        sfFloatRect bounds = sfRectangleShape_getGlobalBounds(button);
        if (sfFloatRect_contains(&bounds, mousePos.x, mousePos.y)) {
            sfRenderWindow_drawText(window, text, NULL);
        }
    }
}
