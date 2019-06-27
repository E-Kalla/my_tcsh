/*
** EPITECH PROJECT, 2018
** putnbr
** File description:
** nbr
*/

#include "../my.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    else {
        my_putchar (nb + 48);
    }
    return (0);
}
