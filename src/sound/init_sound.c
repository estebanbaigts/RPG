/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** init_sound
*/

#include <SFML/Audio.h>
#include "game.h"
#include "sound.h"

void destroy(game_t *game)
{
    sfMusic_stop(game->sounds.back_sound);
    sfMusic_destroy(game->sounds.back_sound);
    sfMusic_stop(game->sounds.foot_step);
    sfMusic_destroy(game->sounds.foot_step);
}

void init_sound(game_t *game)
{
    game->sounds.back_sound = sfMusic_createFromFile("./audio/back_sound.ogg");
    sfMusic_setVolume (game->sounds.back_sound, 10.0);
    game->sounds.foot_step = sfMusic_createFromFile("./audio/footstep.ogg");

}
