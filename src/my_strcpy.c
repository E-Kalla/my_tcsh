/*
** EPITECH PROJECT, 2018
** strcpy
** File description:
** copy
*/

#include "../my.h"
#include <stdlib.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    int len = my_strlen(src);

    dest = malloc(sizeof(char) * len + 1);

    while (src[i] != '\0') {
        dest[i] = src[i];
        i += 1;
    }
    return (dest);
}

char *my_home(char *dest, char *src)
{
    int i = 5;
    int j = 0;
    int len = my_strlen(src);

    dest = malloc(sizeof(char) * len + 1);

    while (src[i] != '\0') {
        dest[j] = src[i];
        i += 1;
        j += 1;
    }
    return (dest);
}