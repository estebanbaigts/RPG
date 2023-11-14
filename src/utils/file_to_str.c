/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-myrpg-noa.messer
** File description:
** file_to_str
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

char *file_to_str(char const *path)
{
    FILE *fd;
    char *buffer;
    if (!path)
        return NULL;

    struct stat sfile;
    stat(path, &sfile);
    fd = fopen(path, "r");
    int size = sfile.st_size;
    buffer = malloc(size);
    if (!buffer)
        return NULL;

    fread(buffer, 1, size, fd);
    fclose(fd);
    buffer[size] = 0;
    return buffer;
}
