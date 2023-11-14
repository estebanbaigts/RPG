/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** text
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

#ifndef TEXT_H_
    #define TEXT_H_

typedef struct text_s {
    sfText *text;
    sfFont *font;
    float size;
    sfBool show;
    sfBool key_x;
    int id;
    sfSprite *sprite;
    sfTexture *texture;
} text_t;

#endif /* !TEXT_H_ */
