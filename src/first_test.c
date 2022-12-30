/*
** EPITECH PROJECT, 2022
** pussssssssssssssssss
** File description:
** first_test
*/

#include "my.h"

void test_sa(pushswap_t *pushswap)
{
    write(1, "sa", 2);
    pushswap->sorted = true;
}

void test_ra(dlist_t *test, pushswap_t *pushswap)
{
    test = my_ra(test);
    pushswap->sorted = (sorted(test) == 0) ? true : false;
}

void test_rra(dlist_t *test, pushswap_t *pushswap)
{
    test = my_rra(test);
    test = my_rra(test);
    pushswap->sorted = (sorted(test) == 0) ? true : false;
}

void first_test(dlist_t *test, pushswap_t *pushswap)
{
    int nb_node = 0;
    dlistnode_t *tmp = test->begin;
    while (tmp) {
        nb_node++;
        tmp = tmp->next;
    }
    if (nb_node == 2){
        test_sa(pushswap);
        return;
    }
    test_ra(test, pushswap);
    if (pushswap->sorted == true){
        write(1, "ra", 2);
        return;
    }
    test_rra(test, pushswap);
    if (pushswap->sorted == true){
        write(1, "rra", 3);
        return;
    }
}
