/*
** EPITECH PROJECT, 2021
** my_realloc
** File description:
** reallocation of memory
*/

#include "my.h"
#include <stdlib.h>

char *my_realloc2(char *str)
{
    int len = my_strlen(str);
    char *strcpy = malloc(sizeof(char) * len + 2);

    for (int i = 0; str[i] == '\0'; i++) {
        strcpy[i] = str[i];
    }
    strcpy[len + 1] = '\0';
    free (str);
    return (strcpy);
}
