/*
** EPITECH PROJECT, 2022
** finalpushswap
** File description:
** main
*/

#include "my.h"

void my_setup(dlist_t *l_a, pushswap_t *pushswap, int ac)
{
    int hight_nb = -2147483648;
    int small_nb = 2147483647;
    dlistnode_t *tmp = l_a->begin;

    for (int i = 1; i < ac; i++) {
        if (tmp->nb > hight_nb)
            hight_nb = tmp->nb;
        if (tmp->nb < small_nb)
            small_nb = tmp->nb;
        tmp = tmp->next;
    }

    pushswap->total_nb = ac - 1;
    pushswap->hight_nb = hight_nb;
    pushswap->small_nb = small_nb;
    pushswap->total_nb_l_a = ac - 1;
    pushswap->total_nb_l_b = 0;
    return;
}

void pushswap(int ac, char **av)
{
    dlist_t *l_a = NULL;
    dlist_t *l_b = NULL;
    dlist_t *test = NULL;
    pushswap_t *pushswap = malloc(sizeof(pushswap_t));
    for (int i = ac; i > 1; i--){
        l_a = remp_list(l_a, my_convert_to_nbr(av[i - 1]));
        test = remp_list(test, my_convert_to_nbr(av[i - 1]));
    }
    pushswap->sorted = (sorted(l_a) == 0) ? true : false;
    if (pushswap->sorted == false)
        first_test(test, pushswap);
    if (pushswap->sorted == true){
        write(1, "\n", 1);
        return;
    }
    first_sort(ac, av, pushswap);
    my_setup(pushswap->l_a, pushswap, ac);
    l_a = set_pos(pushswap, l_a);
    radix_sort(l_a, l_b, pushswap);
    write(1, "\n", 1);
}

int error_handling(char **str, int j)
{
    for (int i = 0; str[j][i]; i++){
        if (!(str[j][i] >= '0' && str[j][i] <= '9') && (str[j][i] != '-'))
            return (1);
        if (str[j][i] == '-' && i != 0)
            return (1);
        if (str[j][i] == '-' && !(str[j][i + 1]))
            return (1);
    }
    return (0);
}

int main (int ac, char **av)
{
    int error = 0;

    if (ac == 1)
        return (0);

    for (int j = 1; av[j]; j++){
        error = error_handling(av, j);
        if (error == 1)
            return (84);
    }

    if (ac == 2) {
        write (1, "\n", 1);
        return (0);
    }

    pushswap(ac, av);
    return (0);
}
