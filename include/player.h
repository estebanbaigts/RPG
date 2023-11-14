/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** player
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

#ifndef PLAYER_H_
    #define PLAYER_H_

enum e_player_move {
    UP = 0,
    DOWN,
    RIGHT,
    LEFT
};

enum e_player_action {
    IDLE = 0,
    WALK,
    ATTACK
};

typedef struct player_s {
    sfSprite *sprite;
    sfTexture *texture[3];
    sfBool move[4];
    float x;
    float y;
    sfFloatRect hitbox;
    enum e_player_move facing;
    enum e_player_action stat;
    int frame;
    sfBool lock;
} player_t;

#endif /* !PLAYER_H_ */
