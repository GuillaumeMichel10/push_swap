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
    pushswap->nb_moov = 0;
    return;
}

void pushswap(int ac, char **av)
{
    dlist_t *l_a = NULL;
    dlist_t *l_b = NULL;
    pushswap_t *pushswap = malloc(sizeof(pushswap_t));

    for (int i = ac; i > 1; i--)
        pushswap->l_a = remp_list(pushswap->l_a, my_convert_to_nbr(av[i - 1]));
    for (int i = ac; i > 1; i--)
        l_a = remp_list(l_a, my_convert_to_nbr(av[i - 1]));


    my_setup(pushswap->l_a, pushswap, ac);
    
    printf("%d\n", pushswap->total_nb_l_a);

    first_sort(pushswap);


    printf("%d\n", pushswap->nb_moov);

    if (pushswap->sorted == true)
        return;

    l_a = set_pos(pushswap, l_a);
    radix_sort(l_a, l_b, pushswap);
    write(1, "\n", 1);

    return;
}

int main (int ac, char **av)
{
    if (ac == 1)
        return (0);
    if (ac == 2) {
        write (1, "\n", 1);
        return (0);
    }
    pushswap(ac, av);

    return (0);
}
