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
#define bool unsigned int
#define true 1
#define false 0

typedef struct dlistnode_s {
    int nb;
    int pos;
    struct dlistnode_s *prev;
    struct dlistnode_s *next;
}dlistnode_t;

typedef struct dlist_s {
    struct dlistnode_s *begin;
    struct dlistnode_s *end;
}dlist_t;

typedef struct place_s{
    int min;
    int place;
}place_t;

typedef struct pushswap_s {
    int hight_nb;
    int small_nb;
    int total_nb_l_a;
    int total_nb_l_b;
    int total_nb;
    bool sorted;
    dlist_t *l_a;
    dlist_t *l_b;
}pushswap_t;

dlist_t *rm_node(dlist_t *li);
int my_convert_to_nbr(char *str);
dlist_t *my_ra(dlist_t *list);
dlist_t *remp_list(dlist_t *li, int nb);
dlist_t *my_pa(dlist_t *l_b, int nb);
dlist_t *my_pb(dlist_t *l_b, int nb);
dlist_t *my_sa(dlist_t *list);
dlist_t *my_rra(dlist_t *list);
void radix_sort(dlist_t *l_a, dlist_t *l_b, pushswap_t *pushswap);
dlist_t *final_sort(dlist_t *l_a, pushswap_t *pushswap, dlist_t *l_b, int i);
dlist_t *all_in_l_a(dlist_t *l_a, pushswap_t *pushswap, dlist_t *l_b, int x);
int sorted(dlist_t *l_a);
dlist_t *set_pos(pushswap_t *pushswap, dlist_t *l_a);
void first_sort(int ac, char **av, pushswap_t *pushswap);
void first_test(dlist_t *test, pushswap_t *pushswap);
