/*
** EPITECH PROJECT, 2022
** finalpushswap
** File description:
** my_list
*/

#include "my.h"

dlist_t *rm_node(dlist_t *li)
{
    if (li == NULL)
        return NULL;
    if (li->begin == li->end){
        free(li);
        li = NULL;
        return NULL;
    }
    dlistnode_t *tmp = li->begin;
    li->begin = li->begin->next;
    li->begin->prev = NULL;
    tmp->next = NULL;
    tmp->prev = NULL;
    free(tmp);
    tmp = NULL;
    li->length--;
    return (li);
}

dlist_t *remp_list(dlist_t *li, int nb)
{
    dlistnode_t *node = malloc(sizeof(dlistnode_t));
    if (node == NULL)
        return NULL;
    node->nb = nb;
    node->next = NULL;
    node->prev = NULL;
    if (!li){
        li = malloc(sizeof(dlist_t));
        if (li == NULL)
            return NULL;
        li->begin = node;
        li->end = node;
    } else {
        li->begin->prev = node;
        node->next = li->begin;
        li->begin = node;
    }
    return (li);
}
