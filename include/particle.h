/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** particle
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

#ifndef PARTICLE_H_
    #define PARTICLE_H_

typedef struct particle_s {
    sfSprite *sprite;
    struct particle_s *next;
} particle_t;

#endif /* !PARTICLE_H_ */
