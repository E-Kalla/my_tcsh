/*
** EPITECH PROJECT, 2018
** stumper
** File description:
** str _ to tab
*/

#include <stdlib.h>
#include "../my.h"

int     how_many_cmd(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == ';')
            nb += 1;
    }
    return (nb);
}

int		my_count(char *str, char c)
{
    int	i = 0;
    int	count = 0;

    while (str[i] != '\0') {
        while (str[i] && (str[i] == c || str[i] == '\t'))
            i++;
        if (str[i])
            count++;
        if (str[i] != '\0')
            i++;
    }
    return (count);
}

int		my_strlentab(const char *str, char c)
{
    int	i = -1;

    while (str[++i] != '\0' && str[i] != c && str[i] != '\t');
    return (i);
}

char		**get_tab(char *str, char c)
{
    char    **tab;
    int	i = 0;
    int	z = -1;
    int	j;

    if ((tab = malloc((my_count(str, c) + 1) * sizeof(*tab))) == NULL)
        my_puterror("Problem with a memory allocation(2)");
    while (str[i]) {
        j = 0;
        while (str[i] && (str[i] == c))
            ++i;
        if ((tab[++z] = malloc((my_strlentab(&str[i], c) + 1)
			     * sizeof(**tab))) == NULL)
            my_puterror("Problem with a memory allocation(3)");
        while (str[i] && str[i] != c)
            tab[z][j++] = str[i++];
        tab[z][j] = '\0';
        while (str[i] && (str[i] == c))
            ++i;
    }
    tab[z + 1] = '\0';
    return (tab);
}