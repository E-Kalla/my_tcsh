/*
** EPITECH PROJECT, 2019
** minishell2
** File description:
** clen str
*/

#include "../my.h"
#include <stdio.h>
#include <stdlib.h>

int move_str(char *str, int i)
{
    while (str[i] != '\0') {
        str[i] = str[i + 1];
        i += 1;
    }
    return (0);
}

char    *more_clean(char *str)
{
    char *tmp = malloc(sizeof(char) * my_strlen(str));
    int j = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] != ';') {
            tmp[j] = str[i];
            j += 1;
        }
    }
    return (tmp);
}
char    *clean_str(char *str)
{
    int i = 0;
    int n = 0;

    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\t')
            i += 1;
        else if ((str[i] == ' ' && str[i - 1] != ' ') ||
            (str[i] == '\t' && str[i - 1] != ' ')) {
            str[i] = ' ';
            i += 1;
        } else
            move_str(str, i);
    }
    if (str[i - 1] == ' ')
        str[i - 1] = '\0';
    if (str[i] == ' ')
        str[i] = '\0';
    while (str[n] == ' ')
        move_str(str, n);
    return (str);
}