/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** player_stat
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

#ifndef PLAYER_STAT_H_
    #define PLAYER_STAT_H_

enum e_stat_texture {
    HP = 0
};

typedef struct hp_sprite_s {
    sfSprite *sprite;
    int id;
} hp_sprite_t;

typedef struct stat_s {
    int hp;
    int max_hp;
    int damage;
    sfTexture *texture[1];
    hp_sprite_t hp_sprite[10];
} stat_t;

#endif /* !PLAYER_STAT_H_ */
