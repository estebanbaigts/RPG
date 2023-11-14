/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** enemies
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "map.h"

#ifndef ENEMIES_H_
    #define ENEMIES_H_

enum e_enemie_list {
    ghoul = 0
};

static char *enemie_name[] = {
    "ghoul",
    NULL
};

enum e_enemie_clock {
    G_ANIMATION = 0,
    G_ATTACK_DELAY
};

enum e_enemie_stat {
    G_IDLE = 0,
    G_WALK,
    G_ATTACK,
    G_DEATH
};

typedef struct ghoul_s {
    sfSprite *sprite;
    sfBool alive;
    sfBool invincible;
    float spawn_x;
    float spawn_y;
    float x;
    float y;
    sfClock *clock[3];
    sfBool move[4];
    enum e_enemie_stat stat;
    int frame;
    sfFloatRect hitbox;
    int hp;
    enum e_map_stat map;
} ghoul_t;

typedef struct ghoul_list_s {
    ghoul_t element;
    struct ghoul_list_s *next;
} ghoul_list_t;

typedef struct all_enemies_s {
    sfTexture *texture[1];
    ghoul_list_t *ghoul_list;
    sfBool one_time;
} all_enemies_t;

typedef struct enemies_pos_s {
    enum e_enemie_list type;
    int spawn_x;
    int spawn_y;
    enum e_map_stat map;
}enemies_pos_t;

static enemies_pos_t enemies_pos_list[] = {
    {ghoul, 720, 760, village},
    {ghoul, 868, 630, village},
    {0, 0, 0}
};

#endif /* !ENEMIES_H_ */
