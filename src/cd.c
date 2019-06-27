/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** cd
*/

#include "../my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char    *get_home(t_opt *opt)
{
    int i = 0;
    char *tmp = NULL;
    
    while (opt->myenv[i] != NULL) {
        if (find_home(opt->myenv[i],"HOME=") == 1) {
            tmp = my_home(tmp,opt->myenv[i]);
            return (tmp);
        }
        i += 1;
    }
    free (tmp);
    return (opt->myenv[i]);
}

int     cd_home(t_opt *opt)
{
    char *dir = malloc(sizeof(char) * 100);

    dir = get_home(opt);
    chdir(dir);
    return (0);
}

void    free_tab(char **cmd)
{
    for (int i = 0; cmd[i] != NULL; i += 1)
        free(cmd[i]);
    free (cmd);
}

int     error_cd(char **cmd)
{
    if (cmd[2] != NULL) {
        my_puterror("cd: Too many arguments.\n");
        free_tab(cmd);
        return (-1);
    }
    if (cmd[1] != NULL && (my_strlen(cmd[1]) > 1) &&
        cmd[1][0] != '-' && chdir(cmd[1]) == -1) {
        my_putstr(cmd[1]);
        my_putstr(": No such file or directory.\n");
        free_tab(cmd);
        return (-1);
    }
    return (0);
}

char    *cd(char *choice, char *oldpwd, t_opt *opt)
{
    char *pwd = malloc(sizeof(char) * 100);
    char ** cmd;
    size_t size = 100;

    pwd = getcwd(pwd,size);
    cmd = get_tab(choice,' ');
    if (error_cd(cmd) == -1)
        return (oldpwd);
    if (cmd[1] == NULL) {
        pwd = getcwd(pwd,size);
        cd_home(opt);
        free_tab(cmd);
        return (pwd);
    }
    if (cmd[1][0] == '-') {
        if (oldpwd == NULL || chdir(oldpwd) == -1) {
            my_puterror(oldpwd);
            my_puterror(": No such file or directory.\n");
        }
        chdir(oldpwd);
    }
    if (my_strcmp(pwd,oldpwd) == 0) {
        free_tab(cmd);
        return (oldpwd);
    }
    free_tab(cmd);
    return (pwd);
}