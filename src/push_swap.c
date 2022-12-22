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

place_t test(int *nbrs, int i, place_t place)
{
    if (nbrs[i] < place.min){
        place.place = i;
        place.min = nbrs[i];
    }
    return (place);
}

void sort(int ac, int *nbrs, pushswap_t *pushswap)
{
    place_t place;
    place.min = __INT_MAX__;
    place.place = 0;
    int tmp = 0;

    for (int j = 0; j < ac - 1; j++){
        for (int i = j; i < ac - 1; i++){
            place = test(nbrs, i, place);
        }
        tmp = nbrs[j];
        nbrs[j] = place.min;
        nbrs[place.place] = tmp;
        place.min = __INT_MAX__;
    }

    for (int i = ac - 1; i > 0; i--)
        pushswap->l_a = remp_list(pushswap->l_a, nbrs[i - 1]);
}

void first_sort(int ac, char **av, pushswap_t *pushswap)
{
    int *nbrs = malloc(sizeof(int) * ac);

    for (int i = 0; i < ac - 1; i++)
        nbrs[i] = my_convert_to_nbr(av[i + 1]);

    sort(ac, nbrs, pushswap);
    free (nbrs);

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
