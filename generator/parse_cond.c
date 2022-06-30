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

void modifying_pos(all_pos_t *pos, int new_i, int new_j)
{
    all_pos_t pos2[] = {{new_i + 2, new_j}, {new_i, new_j + 2},\
    {new_i - 2, new_j}, {new_i, new_j - 2}};

    for (int i = 0; i != 4; i++) {
        pos[i].i = pos2[i].i;
        pos[i].j = pos2[i].j;
    }
}

movable_pos_t *multiple_way(int nb_pos, movable_pos_t *movable_pos,
    memo_pos_t **pos, char **map)
{
    memo_pos_t *new_pos;
    int which = 0;

    which = rand() % nb_pos;
    for (; which != 0; which--)
        movable_pos = movable_pos->next;
    new_pos = malloc(sizeof(memo_pos_t));
    new_pos->i = movable_pos->i;
    new_pos->j = movable_pos->j;
    map[movable_pos->mid_i][movable_pos->mid_j] = '*';
    map[movable_pos->i][movable_pos->j] = '*';
    new_pos->next = *pos;
    *pos = new_pos;
    return (movable_pos);
}
