/*
** EPITECH PROJECT, 2018
** strncpy
** File description:
** copy n
*/

char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    while(i < n) {
        dest[i] = src[i];
        i += 1;
    }
    return (dest);
}
