/*
** EPITECH PROJECT, 2022
** dante's star
** File description:
** main generator
*/
#include <time.h>
#include <stdlib.h>
#include "dante.h"
#include <unistd.h>
#include <stdio.h>

void no_name_funct(store_all_pos_t *store_all, int *nb_pos, int i, int j)
{
    (void)j;

    if (A_POS[i].i > my_tablen(store_all->map) - 1 || \
    A_POS[i].i < 0 || A_POS[i].j > my_strlen(store_all->map[0]) \
    - 1 || A_POS[i].j < 0) {
        return;
    } else if (store_all->map[A_POS[i].i][A_POS[i].j] && store_all->map\
    [A_POS[i].i][A_POS[i].j] == 'X') {
        check_validity(store_all->map, store_all, &MV_POS, i);
        *nb_pos = *nb_pos + 1;
    }
}

int parse_maze(char **map, struct memo_pos_s *pos, int i, int j)
{
    all_pos_t all_pos2[] = {{i + 2, j}, {i, j + 2},\
    {i - 2, j}, {i, j - 2}};
    all_pos_t all_pos_write[] = {{i + 1, j}, {i, j + 1},\
    {i - 1, j}, {i, j - 1}};
    all_pos_t *all_pos = malloc(sizeof(all_pos_t) * 4);
    copying_pos(all_pos, all_pos2);
    movable_pos_t *movable_pos = NULL;
    store_all_pos_t *store_all = malloc(sizeof(store_all_pos_t));

    store_all->map = map;
    MV_POS = movable_pos;
    POS = pos;
    A_POS = all_pos;
    store_all->all_pose_write = all_pos_write;
    find_movable_pos(store_all);
    return (1);
}

char **finish(char **map)
{
    int t_len = my_tablen(map) - 1;
    int len = my_strlen(map[0]) - 1;

    if (map[t_len - 1][len] == 'X' && map[t_len][len - 1] == 'X') {
        map[t_len - 1][len] = '*';
        map[t_len][len] = '*';
    }
    map[t_len][len] = '*';
    return (map);
}

char **modify(char **map, int i, int j)
{
    int random = rand() % 5;

    if (random == 1)
        map[i][j] = '*';
    return map;
}

char **imperfect(char **map)
{
    for (int i = 0; map[i]; i++) {
        for (int j = 0; map[i][j]; j++)
            map = modify(map, i, j);
    }
    return (map);
}

int main(int ac, char **av)
{
    int i = 0;
    memo_pos_t *start_pos = NULL;
    char **map = create_map(av);

    srand(time(NULL));
    if (ac < 3)
        return 84;
    map[0][0] = '*';
    parse_maze(map, start_pos, 0, 0);
    map = finish(map);
    if (ac == 3)
        map = imperfect(map);
    for (; map[i + 1] != NULL; i++)
        printf("%s\n", map[i]);
    printf("%s", map[i]);
    return (0);
}
