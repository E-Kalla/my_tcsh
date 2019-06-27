/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** mysh
*/

#include "../my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

int     my_bin_path(char *bin, char **arg, char **env,char *path)
{
    pid_t son = fork();
    int status;
    pid_t wait;

    if (son == 0) {
        if (execve(path,arg,env) == -1)
            return (84);
    }
    if (son > 0) {
        wait = waitpid(son,&status,0);
    }
    if (WIFSIGNALED(status) && WTERMSIG(status))
        sigsev();
    return (0);
}

int     where_path(char **env)
{
    int i = 0;

    while (env[i] != NULL) {
        if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' && env[i][3] == 'H')
            return (i);
        i += 1;
    }
}

char **capt_path(char **env)
{
    char **temp;
    int i = where_path(env);

    temp = get_tab(env[i],':');
    return (temp);
}