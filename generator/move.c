/*
** EPITECH PROJECT, 2022
** dante's star
** File description:
** main generator
*/
#include <stdlib.h>
#include "dante.h"
#include <unistd.h>
#include <stdio.h>

void find_movable_pos(store_all_pos_t *store_all)
{
    int nb_pos = 0;
    int i = 0;
    int j = 0;

    while (1) {
        nb_pos = 0;
        i = 0;
        for (int i = 0; i != 4; i++)
            no_name_funct(store_all, &nb_pos, i, j);
        if (find_movable_pos_loop(store_all, nb_pos, &i, &j) == 1)
            return;
    }
}

int finish_test(store_all_pos_t *store_all, int *i, int *j)
{
    if (POS->next == NULL)
        return (1);
    store_all->map[POS->i][POS->j] = '*';
    *i = POS->i;
    *j = POS->j;
    POS = POS->next;
    modifying_pos(A_POS, *i, *j);
    return (0);
}

int find_movable_pos_loop(store_all_pos_t *store_all,
    int nb_pos, int *i, int *j)
{
    if (nb_pos > 1) {
        MV_POS = multiple_way(nb_pos, MV_POS, &POS, store_all->map);
        modifying_pos(A_POS, MV_POS->i, MV_POS->j);
    } else if (nb_pos == 0) {
        return (finish_test(store_all, i, j));
    } else {
        store_all->map[MV_POS->mid_i][MV_POS->mid_j] = '*';
        store_all->map[MV_POS->i][MV_POS->j] = '*';
        modifying_pos(A_POS, MV_POS->i, MV_POS->j);
    }
    return (0);
}
