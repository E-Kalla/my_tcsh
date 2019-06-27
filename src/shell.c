/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** shell.c
*/

#include "../my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void    display_env(t_opt *opt)
{
    int i = 0;

    while (opt->myenv[i] != NULL) {
        my_putstr(opt->myenv[i]);
        my_putchar('\n');
        i += 1;
    }
}

int    op(char *str)
{
    if (my_strlen(str) == 0)
        return (0);
    if (str[0] == ';' && my_strlen(str) == 1) 
        return (0);
    return (1);
}

char    *minishell(char *choice,t_opt *opt, char **envi, char *oldpwd)
{
    if (find_cd(choice,"cd")) {
        oldpwd = cd(choice,oldpwd,opt);
        return (oldpwd);
    }
    else if (access_error(choice));
    else if (find(choice,"exit")) {
        my_putstr("exit\n");
        exit (0);
    }
    else if (choice[0] == '.' && choice[1] == '/')
        ex(opt,choice);
    else 
        if (command(choice,envi,opt)) {
            my_puterror(choice);
            my_puterror(": Command not found.\n");
        }
    return (oldpwd);
}

int     shell(t_opt *opt, char **envi)
{
    char *choice = malloc(sizeof(char) * 400);
    int fd = 0;
    int i = 0;
    char **command;
    char *oldpwd;
    
    my_putstr("$>");
    oldpwd[0] = '\0';
    while ((fd = read(0,choice,300)) > 0) {
        choice[fd-1] = '\0';
        command = get_tab(choice,';');
        command[how_many_cmd(choice)+1] = NULL;
        if (op(choice))
            while (command[i] != NULL) {
                command = get_tab(choice,';');
                command[i] = clean_str(command[i]);
                command[i] = more_clean(command[i]);
                oldpwd = minishell(command[i],opt,envi,oldpwd);
                i += 1;
            }
        i = 0;
        my_putstr("$>");
    }
    my_putstr("exit\n");
    return (1);
    free (choice);
}