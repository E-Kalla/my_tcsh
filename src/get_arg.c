/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** get_arg
*/

#include "../my.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char    *catch_arg(char *choice)
{
    int i = 2;
    int j = 0;
    char *temp = malloc(sizeof(char) * my_strlen(choice));

    while (choice[i] != '\0') {
        temp[j] = choice[i];
        i += 1;
        j += 1;
    }
    return (temp);
}

char    **get_arg(char *choice)
{
    char **temp;
    char *arg;
    int i = 0;

    arg = catch_arg(choice);
    temp = get_tab(arg,' ');
    return (temp);
}