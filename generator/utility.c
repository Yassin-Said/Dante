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

void copying_pos(all_pos_t *all_pos, all_pos_t *all_pos2)
{
    for (int i = 0; i != 4; i++) {
        all_pos[i].i = all_pos2[i].i;
        all_pos[i].j = all_pos2[i].j;
    }
}

int my_tablen(char **tab)
{
    int i = 0;

    while (tab && tab[i] != NULL)
        i++;
    return (i);
}

char **create_map(char **av)
{
    char **map = malloc(sizeof(char *) * (atoi(av[2]) + 1));
    int j = 0;
    int i = 0;

    for (; i != atoi(av[2]); i++) {
        map[i] = malloc(sizeof(char) * atoi(av[1]) + 1);
        for (; j != atoi(av[1]); j++)
            map[i][j] = 'X';
        map[i][j] = '\0';
        j = 0;
    }
    map[i] = NULL;
    return (map);
}

int check_validity(char **map, store_all_pos_t *store_all,
    movable_pos_t **movable_pos, int i)
{
    (void)map;
    movable_pos_t *new_pos = NULL;
    new_pos = malloc(sizeof(movable_pos_t));
    new_pos->next = *movable_pos;
    new_pos->i = store_all->all_pos[i].i;
    new_pos->j = store_all->all_pos[i].j;
    new_pos->mid_i = new_pos->i - store_all->all_pose_write[i].i;
    new_pos->mid_j = new_pos->j - store_all->all_pose_write[i].j;
    *movable_pos = new_pos;
    return (1);
}

int len_li_list(memo_pos_t *pos)
{
    int incr = 0;
    memo_pos_t *parse = pos;

    while (parse != NULL) {
        parse = parse->next;
        incr++;
    }
    return (incr);
}
