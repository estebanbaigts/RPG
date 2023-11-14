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

int nb_digit(int nb)
{
    int num_digits = 0;
    if (nb < 0) {
        nb *= -1;
    }
    while (nb != 0) {
        num_digits++;
        nb /= 10;
    }
    return num_digits;
}

char *init_str(bool is_neg, int nb_digits, FILE *file)
{
    char *str = malloc((nb_digits + 1) * sizeof(char));
    if (is_neg) {
        fwrite("-", 1, 1, file);
    }
    return str;
}

char *intToChar(int n, FILE *file)
{
    char* str = NULL;
    int index = 0;
    int digit = 0;
    bool is_neg = false;
    int num_digits = nb_digit(n);
    if (n < 0) {
        is_neg = true;
        n *= -1;
    }
    str = init_str(is_neg, num_digits, file);
    index = num_digits - 1;
    while (n != 0) {
        digit = n % 10;
        str[index] = digit + '0';
        n /= 10;
        index--;
    }
    str[num_digits] = '\0';
    return str;
}

void save_stat(int stat, FILE *file)
{
    printf("%d\n", stat);
    char *buffer = intToChar(stat, file);
    int size = 0;
    fwrite(buffer, 1, my_strlen(buffer), file);
    fwrite("\n", 1, 1, file);
}

void save(game_t *game)
{
    FILE *file = NULL;
    char *buffer = NULL;
    int size = 0;
    file = fopen("./src/save/save.txt", "w");
    save_stat(game->stat.hp, file);
    save_stat(game->stat.max_hp, file);
    save_stat(game->stat.damage, file);
    save_stat(game->player.x, file);
    save_stat(game->player.y, file);
    fclose(file);
}
