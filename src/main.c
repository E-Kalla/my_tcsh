/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** main.c
*/

#include "../my.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int     init_opt(t_opt *opt)
{
    opt->cd = my_strcpy(opt->cd,"cd ");
    opt->env = my_strcpy(opt->env,"env");
    opt->exit = my_strcpy(opt->exit,"exit");
    opt->setenv = my_strcpy(opt->setenv,"setenv ");
    opt->unsetenv = my_strcpy(opt->unsetenv,"unsetenv");
    return (0);
}

int     access_error(char *choice)
{
    if (choice[0] == '.' && my_strlen(choice) == 1) {
        my_putstr("/usr/bin/.: Permission denied.\n");
        return (1);
    }
    else if (choice[0] && choice[1] == '.' && my_strlen(choice) == 2) {
        my_putstr("usr/bin/..: Permission denied.\n");
        return (1);
    }
    return (0);
}

char    **copy_env(char **env)
{
    char **temp;
    int i = 0;

    while (env[i] != NULL) {
        i += 1;
    }
    temp = malloc(sizeof(char*) * i + 1);
    i = 0;
    while (env[i]) {
        temp[i] = my_strcpy(temp[i],env[i]);
        i += 1;
    }
    return (temp);
}

int     main(int ac, char **av, char **env)
{
    t_opt opt;

    if (ac != 1)
        return (84);
    opt.myenv = copy_env(env);
    init_opt(&opt);
    shell(&opt,env);
    return (1);
}