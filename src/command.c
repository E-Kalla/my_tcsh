/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** command.c
*/

#include "../my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char    *get_cmd(char *choice)
{
    int len = my_strlen(choice);
    char *temp = malloc(sizeof(char) * len);
    int i = 0;
    int a = 0;

    while (choice[i] != ' ' && choice[i] != '\0') {
        temp[a] = choice[i];
        i += 1;
        a += 1;
    }
    return (temp);
    free(temp);
}

char *get_path(char **env, int line)
{
    int i = 0;
    int a = 0;
    char *temp = malloc(sizeof(char) * my_strlen(env[line]));

    while (env[line][i] != ':') {
        i += 1;
    }
    i += 1;
    while (env[line][i] != ':') {
        temp[a] = env[line][i];
        i += 1;
        a += 1;
    }
    temp[a] = '/';
    return (temp);
    free(temp);
}

int     command(char *choice, char **env, t_opt *opt)
{
    char *bin = get_cmd(choice);
    char *exe = malloc(sizeof(char) * my_strlen(choice) + 6);
    char **arg;
    char **path;

    arg = get_tab(choice,' ');
    path = capt_path(env);
    for (int a = 1; path[a] != NULL; a += 1) {
        if (access(my_strcat(path[a],bin),F_OK) == 0) {
            my_bin_path(exe,arg,env,my_strcat(path[a],bin));
            return (0);
        }
    }
    return (1);
}