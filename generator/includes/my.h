/*
** EPITECH PROJECT, 2021
** my
** File description:
** prototype of lib functions
*/
#ifndef ALL_PROTOTYPES_H_
    #define ALL_PROTOTYPES_H_

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
void my_putstr(char *str);
int my_strlen(const char *str);
int my_getnbr(const char *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_isprime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *scr);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
char *my_realloc2(char *tab);
int my_tablen(char **tab);
char *str_format(char *);
char *str_update(char *str);
char *str_unformat(char *str);
char *str_add(char *value_1, char *value_2);
char **pop_tab(char **str, int nb);
char *pop_str(char *str, int nb);
char *char_lower(char *str, char *str2);
char *char_greater(char *str, char *str2);
char *niv_mul(char *str, int i, int *incr_str);
char *is_null(char *str);
char **suppr(char **str);
int c_in_sign_or_base(char expr, char *sin_bas);
int banned_expr_b(char *expr, int i);
int banned_expr_s(char *expr, int i, char *sign);
char **my_str_to_word_array(char *str);

#endif
