/*
** EPITECH PROJECT, 2021
** my_strstr
** File description:
** find an str in an other one
*/

#include <stdio.h>
#include <stddef.h>

int my_strncmp(char const *, char const *, int);

int is_all_here(int i, char *str, char const *to_find)
{
    int len;

    len = 0;
    while (to_find[len] != '\0')
        len++;
    return (my_strncmp(str + i, to_find, len));
}

char *condition(int i, char *str, char const *to_find)
{
    if (str[i] == to_find[0])
        if (is_all_here(i, str, to_find) == 0)
            return (str + i);
}

char *my_strstr(char *str, char const *to_find)
{
    int i;

    i = 0;
    while (str != NULL && str[i]) {
        condition(i, str, to_find);
        i++;
    }
    return (0);
}
