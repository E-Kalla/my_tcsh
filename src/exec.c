/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** exec
*/

#include "../my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

int     my_fork(char *bin, char **arg, char **env)
{
    pid_t son = fork();
    int status;
    pid_t wait;

    if (son == 0) {
        if (execve(bin,arg,env) == -1)
            return (84);
    }
    if (son > 0) {
        wait = waitpid(son,&status,0);
    }
    if (WIFSIGNALED(status) && WTERMSIG(status) == 11)
        sigsev();
    return (0);
}

char    *get_ex(char *choice)
{
    int len = my_strlen(choice);
    char *temp = malloc(sizeof(char) * len);
    int i = 2;
    int a = 0;

    while (choice[i] != ' ' && choice[i] != '\0') {
        temp[a] = choice[i];
        i += 1;
        a += 1;
    }
    return (temp);
}

int     ex(t_opt *opt, char *choice)
{
    char *bin = get_ex(choice);
    char **arg = NULL;
    arg = get_arg(choice);

    if (access(bin,F_OK) == 0) {
        my_fork(bin,arg,opt->myenv);
    } else {
        my_puterror(bin);
        my_puterror(": command not found\n");
        free(bin);
        free(arg);
        return (0);
    }
    return (0);
}

int     isex(t_opt *opt, char *choice)
{
    int i = 0;
    int len = my_strlen(choice);
    char *exec = malloc(sizeof(char) * len);

    if (choice[0] == '.' && choice[1] == '/')  {
        free(exec);
        return (1);
    }
    free(exec);
    return (0);
}