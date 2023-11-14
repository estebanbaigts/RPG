/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** camera
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

#ifndef CAMERA_H_
    #define CAMERA_H_

typedef struct camera_s {
    int x;
    int y;
    sfBool lock;
} camera_t;

#endif /* !CAMERA_H_ */
