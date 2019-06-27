/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** atoi
*/

int my_getnbr(char  const *str)
{
    int nbr = 0;
    int negativ = 1;

    for (int i = 0 ; str[i] != '\0' ; i += 1) {
        if ((str[i] == '-') && '0' < str[i + 1] && str[i + 1] <= '9') {
            negativ = -1;
            if ((str[i] == '-') && (str[i - 1] == '-'))
                negativ = 1;
        }
        if ((str[i] > '0') && (str[i] <= '9')) {
            while ((str[i] > '0') && (str[i] <= '9')) {
                nbr = (nbr * 10) + str[i] - '0';
                i += 1;
            }
            if ((str[i] <= '0') || str[i] > '9') {
                return (nbr * negativ);
            }
        }
    }
    return (nbr * negativ);
}
