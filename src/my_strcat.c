/*
** EPITECH PROJECT, 2018
** strcat
** File description:
** concat
*/

#include "../my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;
    int len = my_strlen(dest) + my_strlen(src);
    char *temp = malloc(sizeof(char) * len);

    while (dest[i]) {
        temp[i] = dest[i];
        i += 1;
    }
    temp[i] = '/';
    i += 1;
    while (src[j]) {
        temp[i] = src[j];
        i += 1;
        j += 1;
    }
    return (temp);
}