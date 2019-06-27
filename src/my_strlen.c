/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** longueur
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i]) {
        i += 1;
    }
    return (i);
}
