/*
** EPITECH PROJECT, 2022
** finalpushswap
** File description:
** subject_fnct
*/

#include "my.h"

dlist_t *my_pb(dlist_t *l_b, int nb)
{
    l_b = remp_list(l_b, nb);
    return (l_b);
}

dlist_t *my_pa(dlist_t *l_a, int nb)
{
    l_a = remp_list(l_a, nb);
    return (l_a);
}

dlist_t *my_ra (dlist_t *list)
{
    if (!list || !list->begin)
        return (NULL);
    if (list->begin == list->end)
        return (list);
    dlistnode_t *first = list->begin;
    dlistnode_t *next = list->begin->next;
    dlistnode_t *last = list->end;

    list->begin = next;
    list->begin->prev = NULL;
    list->end->next = first;
    list->end = list->end->next;
    list->end->next = NULL;
    list->end->prev = last;
    return (list);
}

dlist_t *my_rra(dlist_t *list)
{
    dlistnode_t *prev = NULL;

    if (!list)
        return (NULL);

    if (list->begin == list->end)
        return (list);

    prev = list->end->prev;
    list = remp_list(list, list->end->nb);
    free(list->end);
    list->end = prev;
    list->end->next = NULL;

    return (list);
}

dlist_t *my_sa(dlist_t *list)
{
    if (list->begin->next == list->end){
        list = my_ra(list);
        return (list);
    }

    int nb = list->begin->nb;
    int nb2 = list->begin->next->nb;
    list->begin->nb = nb2;
    list->begin->next->nb = nb;

    return (list);
}

// list_t *my_rb(list_t *list)
// {
//     if (!list->next){
//         return (list);
//     }
//     list_t *tmp = list;
//     list_t *last = list;
//     list_t *next = list->next;

//     while (list){
//         last = list;
//         list = list->next;
//     }
//     list = tmp;
//     last->next = malloc(sizeof(list_t));
//     last->next->nb = tmp->nb;
//     last->next->next = nULL;
//     free(list);

//     return (next);
// }
