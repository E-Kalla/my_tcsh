/*
** EPITECH PROJECT, 2019
** minishells
** File description:
** sigsev
*/

#include "../my.h"
#include <stdlib.h>

void    sigsev()
{
    my_puterror("Segmentation fault\n");
    exit(139);
}