/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** renverse la str
*/

#include <stddef.h>

int my_strlen(char *str);

char *my_revstr(char *str)
{
    int incr;
    char memo;
    int len;

    len = (my_strlen(str) - 1);
    incr = 0;
    while (incr <= len / 2) {
        memo = str[incr];
        str[incr] = str[len - incr];
        str[len - incr] = memo;
        incr++;
    }
    return (str);
}
