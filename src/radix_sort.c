/*
** EPITECH PROJECT, 2022
** bttfpushswap
** File description:
** radix_sort
*/

#include "my.h"

dlist_t *all_in_l_a(dlist_t *l_a, pushswap_t *pushswap, dlist_t *l_b, int x)
{
    for (int j = 0; j < x; j++){
        l_a = my_pa(l_a, l_b->begin->nb);
        write(1, "pa", 2);
        l_b = rm_node(l_b);
        if (j + 1 == x)
            pushswap->sorted = (sorted(l_a) == 0)
            ? true : false;
        if (pushswap->sorted == false)
            write (1, " ", 1);
        pushswap->nb_moov += 1;
    }
    return (l_a);
}

dlist_t *final_sort(dlist_t *l_a, pushswap_t *pushswap, dlist_t *l_b, int i)
{
    int x = 0;
    int num = 0;

    for (int j = 0; j < pushswap->total_nb; j++){
        num = l_a->begin->nb;
        if (((num >> i) & 1) == 1) {
            l_a = my_ra(l_a);
            write(1, "ra ", 3);
        } else {
            x++;
            write(1, "pb ", 3);
            l_a = rm_node(l_a);
            l_b = my_pb(l_b, num);
        }
        pushswap->nb_moov += 1;
    }
    l_a = all_in_l_a(l_a, pushswap, l_b, x);
    return (l_a);
}

void radix_sort(dlist_t *l_a, dlist_t *l_b, pushswap_t *pushswap)
{
    pushswap->sorted = (sorted(l_a) == 0) ? true : false;
    pushswap->nb_moov = 0;

    for (int i = 0; pushswap->sorted == false; i++)
        l_a = final_sort(l_a, pushswap, l_b, i);


    dlistnode_t *tmp = l_a->begin;

    while(tmp){
        printf("%d\n",tmp->nb);
        tmp = tmp->next;
    }

    printf("moov = %d\n", pushswap->nb_moov);
    return;
}
