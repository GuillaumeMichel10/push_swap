/*
** EPITECH PROJECT, 2022
** finalpushswap
** File description:
** push_swap_tester
*/

#include "my.h"

int sorted(dlist_t *l_a)
{
    int nb = -2147483648;
    dlistnode_t *tmp = l_a->begin;

    while (tmp) {
        if (nb <= tmp->nb){
            nb = tmp->nb;
        } else {
            return (84);
        }
        tmp = tmp->next;
    }
    return (0);
}

int main (int ac, char **av)
{
    dlist_t *l_a = malloc(sizeof(dlist_t));
    dlist_t *l_b = malloc(sizeof(dlist_t));
    l_a = NULL;
    l_b = NULL;

    for (int i = ac; i > 1; i--){
        if (av[i - 1][0] == 'r' || av[i - 1][0] == 'p')
            break;
        l_a = remp_list(l_a, my_convert_to_nbr(av[i - 1]));
    }

    dlistnode_t *tmp = l_a->begin;

    for (int i = 0; av[i]; i++){
        if (my_strcmp(av[i], "pa") == 0){
            l_a = my_pa(l_a, l_b->begin->nb);
            l_b = rm_node(l_b);
        }
        if (my_strcmp(av[i], "pb") == 0){
            l_b = my_pb(l_b, l_a->begin->nb);
            l_a = rm_node(l_a);
        }
        if (my_strcmp(av[i], "ra") == 0){
            l_a = my_ra(l_a);
        }
    }
    tmp = l_a->begin;
    while (tmp) {
        printf("%d\n", tmp->nb);
        tmp = tmp->next;
    }
    if (sorted(l_a) == 0){
        printf("Sorted");
    } else {
        printf("Not good");
    }
    return (sorted(l_a));
}