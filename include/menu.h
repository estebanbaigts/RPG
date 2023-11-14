/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** menu
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

#ifndef MENU_H_
    #define MENU_H_

enum e_button_stat {
    UNPRESS = 0,
    HOVER,
    PRESSED
};

enum e_button_type {
    PLAY = 0,
    LOAD,
    SETTING
};

static char *button_name[] = {
    "play",
    "load",
    "setting",
    NULL
};

typedef struct button_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfFloatRect rect;
    enum e_button_type type;
    enum e_button_stat stat;
} button_t;

typedef struct menu_s {
    button_t button[3];
    sfSprite *sprite;
    sfTexture *texture;
    sfBool one_tap;
    sfBool pause;
    sfBool play;
} menu_t;

typedef struct button_list_s {
    sfFloatRect *rect;
    enum e_button_stat stat;
} button_list_t;

static button_list_t button_list[] = {
    {&(sfFloatRect){176, 400, 70, 70}, PLAY},
    {&(sfFloatRect){392, 400, 70, 70}, LOAD},
    {&(sfFloatRect){584, 400, 70, 70}, SETTING},
    {0, 0}
};

#endif /* !MENU_H_ */
