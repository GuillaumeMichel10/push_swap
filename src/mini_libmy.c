/*
** EPITECH PROJECT, 2022
** finalpushswap
** File description:
** mini_libmy
*/

#include "my.h"

void my_putstr(char *str)
{
    for (int i = 0; str[i]; i++){
        write (1, &str[i], 1);
    }
    return;
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;

    return (i);
}

char *my_revstr(char *str)
{
    int j = 0;
    int strlen = my_strlen(str);
    char *nwstr = malloc(sizeof(char) * (strlen + 1));

    nwstr[strlen] = '\0';
    for (int i = strlen - 1; i >= 0; i--, j++){
        nwstr[j] = str[i];
    }
    return (nwstr);
}

int my_convert_to_nbr(char *str)
{
    int nb = 0;
    int i = 0;

    if (str[0] == '-')
        i += 1;

    for (; str[i]; i++){
        nb += str[i] - 48;
        if (str[i + 1])
            nb *= 10;
    }

    if (str[0] == '-')
        nb *= -1;
    return (nb);
}
