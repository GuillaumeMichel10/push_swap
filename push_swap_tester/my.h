/*
** EPITECH PROJECT, 2022
** finalpushswap
** File description:
** my
*/

#pragma once

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct dlistnode_s {
    int nb;
    int pos;
    struct dlistnode_s *prev;
    struct dlistnode_s *next;
}dlistnode_t;

typedef struct dlist_s {
    int length;
    struct dlistnode_s *begin;
    struct dlistnode_s *end;
}dlist_t;

dlist_t *my_pb(dlist_t *l_b, int nb);
dlist_t *my_pa(dlist_t *l_a, int nb);
dlist_t *my_ra (dlist_t *list);
dlist_t *my_rra(dlist_t *list);
dlist_t *my_sa(dlist_t *list);
int my_strcmp (char *str1, char *str2);
int my_convert_to_nbr(char *str);
char *my_revstr(char *str);
int my_strlen(char *str);
void my_putstr(char *str);
dlist_t *remp_list(dlist_t *li, int nb);
dlist_t *rm_node(dlist_t *li);