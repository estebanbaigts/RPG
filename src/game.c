/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** game
*/

#include <SFML/Audio.h>
#include "game.h"
#include "lib.h"

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    if (!game)
        return 0;

    init_window(game);
    init_player(game);
    init_camera(&game->camera);
    init_map(game);
    init_clocks(game);
    init_stat(game);
    init_text(game);
    init_enemies(game);
    init_npc(game);
    init_sound(game);
    init_menu(game);
    return game;
}

void run_game(game_t *game)
{
    sfMusic_setLoop(game->sounds.back_sound, sfTrue);
    sfMusic_play(game->sounds.back_sound);
    while (sfRenderWindow_isOpen(game->window)) {

        sfTime time = sfClock_getElapsedTime(game->clock[GAME_CLOCK]);
        if (sfTime_asSeconds(time) > 0.01) {
            sfml_event(game);
            render(game);
            update(game);
            sfClock_restart(game->clock[GAME_CLOCK]);
        }
    }
}

void start_game(void)
{
    game_t *game = init_game();
    run_game(game);
}
