/*
** EPITECH PROJECT, 2018
** putchar
** File description:
** putput
*/

#include <unistd.h>
#include <stdio.h>

void   my_putchar(char n)
{
    write(1,&n,1);
}
