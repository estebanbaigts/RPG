/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** npc
*/

#include "map.h"
#include "text.h"

#ifndef NPC_H_
    #define NPC_H_

enum e_npc {
    pancarte = 0,
    villageois
};

typedef struct npc_s {
    sfSprite *sprite;
    sfFloatRect box;
    float x;
    float y;
    enum e_map_stat map;
    void (*dialogue)(text_t*);
} npc_t;

typedef struct npc_list_s {
    npc_t npc[1];
    sfTexture *npc_texture[2];
    sfTexture *bubble_texture;
    sfSprite *sprite;
    sfBool show;
} npc_list_t;

#endif /* !NPC_H_ */
