/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** find.c
*/

#include <stdio.h>
#include "../my.h"

int     find_home(char *src, char *tofind)
{
    int i = 0;

    if (src[0] == 'H' && src[1] == 'O' && src[2] == 'M' && src[3] == 'E')
        return (1);
    return (0);
}

int     find_cd(char *src, char *tofind)
{
    int i = 0;

    if (src[0] == 'c' && src[1] == 'd') {
        while (src[i] != ' ' && src[i] != '\0') {
            i += 1;
        }
        if (i <= 3)
            return (1);
    }
    return (0);
}

int     find(char *src, char *tofind)
{
    int i = 0;

    while (tofind[i] != '\0') {
        if (src[i] == tofind[i])
            i += 1;
        else
            return (0);
    }
    if (my_strlen(src) == my_strlen(tofind))
        return (1);
    return (0);
}