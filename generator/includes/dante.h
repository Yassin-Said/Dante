/*
** EPITECH PROJECT, 2022
** dante
** File description:
** dante_h
*/

#include "my.h"

#ifndef DANTE_H
    #define DANTE_H
    #define A_POS store_all->all_pos
    #define MV_POS store_all->movable_pos
    #define POS store_all->pos

typedef struct all_pos_s {
    int i;
    int j;
} all_pos_t;

typedef struct movable_pos_s {
    int i;
    int j;
    int mid_i;
    int mid_j;
    struct movable_pos_s *next;
} movable_pos_t;

typedef struct memo_pos_s {
    int i;
    int j;
    struct memo_pos_s *next;
}   memo_pos_t;

typedef struct store_all_pos_s {
    all_pos_t *all_pos;
    all_pos_t *all_pose_write;
    memo_pos_t *pos;
    movable_pos_t *movable_pos;
    char **map;
} store_all_pos_t;

int parse_maze(char **map, struct memo_pos_s *pos, int i, int j);
int len_li_list(memo_pos_t *pos);
int check_validity(char **map, store_all_pos_t *store_all,\
movable_pos_t **movable_pos, int i);
char **create_map(char **av);
int my_tablen(char **tab);
void copying_pos(all_pos_t *all_pos, all_pos_t *all_pos2);
movable_pos_t *multiple_way(int nb_pos, movable_pos_t *movable_pos,\
memo_pos_t **pos, char **map);
void modifying_pos(all_pos_t *pos, int new_i, int new_j);
void find_movable_pos(store_all_pos_t *store_all);
int finish_test(store_all_pos_t *store_all, int *i, int *j);
int find_movable_pos_loop(store_all_pos_t *store_all,
    int nb_pos, int *i, int *j);
void no_name_funct(store_all_pos_t *store_all, int *nb_pos, int i, int j);
int len_mov(movable_pos_t *mv_pos);

#endif /* !DANTE_H */
