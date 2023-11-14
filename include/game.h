/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** game
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>

#include "player.h"
#include "stat.h"
#include "camera.h"
#include "map.h"
#include "text.h"
#include "enemies.h"
#include "npc.h"
#include "sound.h"
#include "menu.h"

#ifndef GAME_H_
    #define GAME_H_

enum e_clock_type {
    P_ANIMATION = 0,
    ATTACK_DELAY,
    GAME_CLOCK
};

typedef struct game_s {
    sfRenderWindow *window;
    player_t player;
    camera_t camera;
    sound_t sounds;
    map_t map;
    stat_t stat;
    sfClock *clock[3];
    text_t text;
    all_enemies_t enemies;
    npc_list_t npc;
    menu_t menu;
} game_t;

// base game function
void start_game(void);
game_t *init_game(void);
void run_game(game_t *game);
void render(game_t *game);
void update(game_t *game);


void init_window(game_t *game);
void sfml_event(game_t *game);
void init_clocks(game_t *game);


// player
void init_player(game_t *game);
void render_player(game_t *game);
void player_event(game_t *game);
void update_player(game_t *game);
void animated_player_idle(game_t *game);
void animated_player(game_t *game, int frame_nbr, float delay);
sfBool collide_with_wall(game_t *game, sfVector2f next);

// camera
void init_camera(camera_t *camera);
void update_camera(game_t *game);

//utils
char *get_path(char const *path, char const *name, char const *format);
sfTexture *load_player_texture(char const *name);
sfTexture *load_texture(char const *path, char const *name);
sfBool player_is_moving(game_t const *game);
char *file_to_str(char const *path);

//map
void init_map(game_t *game);
void update_map(game_t *game);
void render_map(game_t *game);
void can_teleport_player(game_t *game);
void init_layer(game_t *game);
void update_layer(game_t *game);
void render_layer(game_t *game);

//wall
void init_wall(game_t *game);

//stat
void init_stat(game_t *game);
void render_stat(game_t *game);

//npc
void init_npc(game_t *game);
void update_npc(game_t *game);
void render_npc(game_t *game);
void read_text(text_t *text, char *txtPath, int id);
void init_pancarte(game_t *game, npc_t *npc);


//text
void init_text(game_t *game);
void render_text(game_t *game);
void text_event(game_t *game);

//enemies
void init_enemies(game_t *game);
void update_enemies(game_t *game);
void render_enemies(game_t *game);

void init_ghoul(game_t *game, ghoul_list_t *list, enemies_pos_t pos);
void update_ghoul(game_t *game, ghoul_list_t *list);
void render_ghoul(game_t *game, ghoul_list_t *list);
void ghoul_append(game_t *game, ghoul_list_t **list, enemies_pos_t pos);
void render_ghoul_list(game_t *game, ghoul_list_t *list);
void update_ghoul_list(game_t *game, ghoul_list_t **list);

//sounds
void init_sound(game_t *game);
void destroy(game_t *game);
//menu
void init_menu(game_t *game);
void render_menu(game_t *game);
void update_menu(game_t *game);
void pause_update(game_t *game);
//save
void save(game_t *game);
void recup_save(game_t *game);

#endif /* !GAME_H_ */
