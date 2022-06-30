/*
** EPITECH PROJECT, 2021
** my_printf4
** File description:
** my_printf4
*/
#include <stdio.h>
#include "my.h"
#include "printf.h"

int is_nbr(int nb)
{
    if (nb > 47 && nb < 58)
        return (0);
    return (1);
}

int format_nbr(const char *format, int *i)
{
    int incr = 0;
    int incrmemo = 0;

    if (is_nbr(format[*i + 1] == 0)) {
        incr = my_getnbr(format + *i + 1);
    }
    incrmemo = incr;
    while (incr != 0) {
        incr = incr / 10;
        *i = *i + 1;
    }
    return (incrmemo);
}

int count_print_str(char *str, int spaces)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        count++;
        spaces--;
        i++;
    }
    while (spaces > 0) {
        my_putchar(' ');
        spaces--;
    }
    return (count);
}

void is_point(struct detail *det)
{
    if (det->str[*det->index + 1] == '.') {
        *det->index = *det->index + 1;
        det->point = format_nbr(det->str, det->index);
    }
}

void put_zero(int nb, struct detail *det)
{
    int memo = 0;

    if (nb == 0)
        det->point = det->point - 1;
    for (; nb > 0; nb /= 10) {
        det->point = det->point - 1;
    }
    memo = det->point;
    for (; det->point > 0; det->point = det->point - 1) {
        det->spaces--;
    }
    det->point = memo;
}
