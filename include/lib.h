/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** lib
*/

#ifndef LIB_H_
    #define LIB_H_

int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
char *my_strndup(char const *src, int n);
int my_strlen_to_c(char const *str, char c);
int count_char(char const *str, char c);
char *my_strcdup(char const *src, char c);

#endif /* !LIB_H_ */
