/*
** EPITECH PROJECT, 2022
** bttfpushswap
** File description:
** set_pos
*/

#include "my.h"

dlist_t *invert(dlist_t *l_a)
{
    dlistnode_t *tmp = l_a->begin;

    while (tmp){
        tmp->nb = tmp->pos;
        tmp = tmp->next;
    }

    return (l_a);
}

dlist_t *set_pos(pushswap_t *pushswap, dlist_t *l_a)
{
    int pos = 1;
    dlistnode_t *tmp = pushswap->l_a->begin;
    dlistnode_t *test = l_a->begin;

    while (tmp){
        tmp->pos = pos;
        pos += 1;
        tmp = tmp->next;
    }
    while (pushswap->l_a) {
        if (test->nb == pushswap->l_a->begin->nb){
            test->pos = pushswap->l_a->begin->pos;
            pushswap->l_a = rm_node(pushswap->l_a);
            test = l_a->begin;
        } else {
            test = test->next;
        }
    }
    l_a = invert(l_a);
    return (l_a);
}
