/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** map
*/

#include "global.h"

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

#ifndef MAP_H_
    #define MAP_H_

static const sfFloatRect NULL_RECT = (sfFloatRect){0, 0, 0, 0};

enum e_map_stat {
    plain = 1,
    village,
    base,
    tower,
    castle_base,
    grotte,
    bonus
};

static char *maps_name[] = {
    "null",
    "plain",
    "village",
    "base",
    "tower",
    "castle_base",
    "grotte",
    "bonus",
    NULL
};

typedef struct layer_s {
    sfSprite *sprite;
    sfTexture *texture[8];
} layer_t;

typedef struct map_s {
    sfSprite *sprite;
    sfTexture *texture[8];
    enum e_map_stat stat;
    sfImage *wall[8];
    layer_t layer;
} map_t;

typedef struct map_tp_s {
    sfFloatRect *rect;
    float tp_x;
    float tp_y;
    enum e_map_stat map;
    enum e_map_stat where;
} map_tp_t;

static map_tp_t map_tp_list[] = {
    {&(sfFloatRect){380, 200, 100, 20}, -350, -1760, grotte,  plain},
    {&(sfFloatRect){280, 1850, 150, 20}, -380, -280, plain, grotte},
    {&(sfFloatRect){1536, 1600, -20, 100}, -45, -770, plain,  village},
    {&(sfFloatRect){0, 700, 20, 100}, -1480, -1628, village, plain},
    {&(sfFloatRect){250, 190, 100, 10}, -350, -450, village,  bonus},
    {&(sfFloatRect){350, 500, 20, 100}, -270, -250, bonus, village},
    {&(sfFloatRect){10, 1190, 10, 200}, -1130, -520, plain,  base},
    {&(sfFloatRect){1200, 520, -20, 100}, -50, -1200, base, plain},
    {&(sfFloatRect){10, 1190, 10, 200}, -572, -1438, plain,  tower},
    {&(sfFloatRect){522, 1518, 200, 10}, -30, -1190, tower, plain},
    {0, 0, 0, 0, 0}
};

#endif /* !MAP_H_ */
