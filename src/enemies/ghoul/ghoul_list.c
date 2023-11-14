/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** ghoul_list
*/

#include "game.h"

void ghoul_append(game_t *game, ghoul_list_t **list, enemies_pos_t pos)
{
    ghoul_list_t *tmp = malloc(sizeof(struct ghoul_list_s));
    init_ghoul(game, tmp, pos);
    tmp->next = *list;
    *list = tmp;
}

static void ghoul_kill(game_t *game, ghoul_list_t **list)
{
    ghoul_list_t *tmp = *list;
    ghoul_list_t *prev = 0;
    if (tmp != 0 && !tmp->element.alive) {
        *list = tmp->next;
        free(tmp);
        return;
    }
    while (tmp && !tmp->element.alive) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return;

    prev->next = tmp->next;
    free(tmp);
}

void render_ghoul_list(game_t *game, ghoul_list_t *list)
{
    ghoul_list_t *tmp = list;
    while (tmp) {
        if (tmp->element.map != game->map.stat) {
            tmp = tmp->next;
            continue;
        }
        render_ghoul(game, tmp);
        tmp = tmp->next;
    }
}

void update_ghoul_list(game_t *game, ghoul_list_t **list)
{
    ghoul_list_t *tmp = *list;
    if (tmp == NULL)
        return;

    while (tmp) {
        if (!tmp->element.alive)
            ghoul_kill(game, list);
        if (tmp->element.map != game->map.stat) {
            tmp = tmp->next;
            continue;
        }
        update_ghoul(game, tmp);
        tmp = tmp->next;
    }
}
