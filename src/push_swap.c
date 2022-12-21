/*
** EPITECH PROJECT, 2022
** finalpushswap
** File description:
** push_swap
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

int sorted_pos(dlist_t *l_a)
{
    int nb = -2147483648;
    dlistnode_t *tmp = l_a->begin;

    while (tmp) {
        if (nb <= tmp->pos){
            nb = tmp->pos;
        } else {
            return (84);
        }
        tmp = tmp->next;
    }
    return (0);
}

int test(pushswap_t *pushswap, int small_nb)
{
    if (pushswap->l_a->begin->nb < small_nb){
        small_nb = pushswap->l_a->begin->nb;
    }
    return (small_nb);
}

pushswap_t *sort(pushswap_t *pushswap, int chunk)
{
    int small_nb = 2147483647;

    for (int j = 0; j <= pushswap->total_nb_l_a && pushswap->l_a; j++) {
        if (pushswap->l_a->begin->nb == chunk){
            pushswap->l_b = my_pb(pushswap->l_b, pushswap->l_a->begin->nb,
            pushswap->l_a->begin->pos);
            pushswap->l_a = rm_node(pushswap->l_a);
            pushswap->total_nb_l_a -= 1;
            pushswap->total_nb_l_b += 1;
        } else {
            small_nb = test(pushswap, small_nb);
            pushswap->l_a = my_ra(pushswap->l_a);
        }
    }
    pushswap->small_nb = small_nb;
    return (pushswap);
}

void first_sort(pushswap_t *pushswap)
{
    pushswap->sorted = (sorted(pushswap->l_a) == 0) ? true : false;
    if (pushswap->sorted == true){
        write(1, "\n", 1);
        return;
    }
    for (int i = pushswap->small_nb; pushswap->l_a; i = pushswap->small_nb)
        pushswap = sort(pushswap, i);

    while (pushswap->l_b){
        pushswap->l_a = my_pa(pushswap->l_a, pushswap->l_b->begin->nb,
        pushswap->l_b->begin->pos);
        pushswap->l_b = rm_node(pushswap->l_b);
    }

    return;
}

//int max_bits = 0;
//while ((pushswap->hight_nb >> max_bits) != 0)
//    ++max_bits;
//while (pushswap->l_b){
//     dlistnode_t *tmp = pushswap->l_b->begin;
//     dlistnode_t *tmp2 = pushswap->l_b->end;
//     place = 0;
//     for (int i = 0; i <= 5 && tmp; i++) {
//         if (tmp->nb >= hight_number) {
//             hight_number = tmp->nb;
//             test->place = place;
//         }
//         tmp = tmp->next;
//         place++;
//     }
//     place = 0;
//     for (int i = 0; i <= 5 && tmp2; i++) {
//         // printf("here");
//         if (tmp2->nb >= hight_number) {
//             hight_number = tmp2->nb;
//             test->place = place;
//         }
//         tmp2 = tmp2->prev;
//         place++;
//     }
//     printf("%d\n",pushswap->total_nb_l_b);
//     if (test->place <= (pushswap->total_nb_l_b / 2)){
//         while (pushswap->l_b->begin->nb != hight_number) {
//             pushswap->l_b = my_ra(pushswap->l_b);
//         }
//     } else {
//         while (pushswap->l_b->begin->nb != hight_number){
//             pushswap->l_b = my_rra(pushswap->l_b);
//         }
//     }
//     pushswap->l_a = my_pa(pushswap->l_a, pushswap->l_b->begin->nb);
//     pushswap->l_b = rm_node(pushswap->l_b);
//     pushswap->total_nb_l_b -= 1;
//     hight_number = -2147483648;
// }
