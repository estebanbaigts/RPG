/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** recup_save
*/

#include "game.h"
#include "stat.h"
#include "lib.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

int char_int(char const *arr, int i)
{
    long int nbr = 0;
    int t = 1;
    int number = 0;
    while ('0' <= arr[i] && '9' >= arr[i]){
        number = arr[i] - 48;
        nbr = (nbr * t) + number;
        t = t * 10;
        i = i + 1;
        if (nbr > 2147483647) {
            return (0);
        }
    }
    return (nbr);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int np = 1;
    while (str[i] != '\0' ){
        if (str[i] == '-'){
            np = np * -1;
        }
        if ('0' <= str[i] && '9' >= str[i]){
            return (np * char_int(str, i));
        }
        i = i + 1;
    }
    return (0);
}

void recup_save(game_t *game)
{
    FILE *file = fopen("./src/save/save.txt", "w");
    size_t s = 9;
    char *buf = malloc(sizeof(char) * 10);
    game->stat.hp = my_getnbr(getline(&buf, &s, file));
    game->stat.max_hp = my_getnbr(getline(&buf, &s, file));
    game->stat.damage = my_getnbr(getline(&buf, &s, file));
    game->player.x = my_getnbr(getline(&buf, &s, file));
    game->player.y = my_getnbr(getline(&buf, &s, file));
}
