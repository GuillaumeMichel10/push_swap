/*
** EPITECH PROJECT, 2022
** finalpushswap
** File description:
** mini_libmy
*/

#include "my.h"

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
