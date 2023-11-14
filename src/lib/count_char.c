/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** count_char
*/

int count_char(char const *str, char c)
{
    int nbr = 0;
    if (!str)
        return 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            nbr++;
    }

    return nbr;
}
