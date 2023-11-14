/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** dialogue
*/

#include "game.h"
#include "lib.h"


void read_text(text_t *text, char *txtPath, int id)
{
    if (id == (*text).id) {
        char *str = file_to_str(txtPath);
        sfText_setString((*text).text, str);
        free(str);
    }
}
