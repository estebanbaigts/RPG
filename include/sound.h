/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** sound
*/

#include <SFML/Audio.h>

#ifndef SOUND_H_
    #define SOUND_H_

typedef struct sound_s {
    sfMusic* back_sound;
    sfMusic* foot_step;
} sound_t;

#endif /* !SOUND_H_ */
