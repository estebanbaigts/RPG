/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** particle_list
*/

#include <stdlib.h>
#include "particle.h"

particle_t *init_particle_list(void)
{
    particle_t *list = malloc(sizeof(particle_t));
    list = NULL;
    return list;
}
