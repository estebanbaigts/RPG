/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** my_strlen
*/

int my_strlen_to_c(char const *str, char c)
{
    int i = 0;
    if (!str)
        return 0;

    for (; str[i] && str[i] != c; i++);
    return i;
}

int my_strlen(char const *str)
{
    int i = 0;
    if (!str)
        return 0;

    for (; str[i]; i++);
    return i;
}
