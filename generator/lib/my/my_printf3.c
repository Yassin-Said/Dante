/*
** EPITECH PROJECT, 2021
** my_printf3
** File description:
** other function of my_printf
*/

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include "printf.h"

int count_print(int nb, int spaces)
{
    int count = 0;

    while (nb != 0) {
        nb = nb / 10;
        count++;
        spaces--;
    }
    while (spaces > 0) {
        my_putchar(' ');
        spaces--;
    }
    return (count);
}

void my_putbase(long unsigned nbr, char *base, struct detail *det, char *ext)
{
    char *res = malloc(sizeof(char) * 100);
    int i = 0;
    int len = my_strlen(base);

    nbr = negtest(nbr);
    while (nbr > 0) {
        if (nbr % len > 9) {
            res[i] = base[nbr % len];
            nbr = nbr / len;
            i++;
        } else {
            res[i] = base[nbr % len];
            nbr = nbr / len;
            i++;
        }
    }
    res[i] = '\0';
    display_all_base(det, res, ext);
}

void my_putss(va_list list, struct detail *det)
{
    char octbase[9] = {"01234567\0"};
    unsigned char *str = va_arg(list, unsigned char *);

    for (int i = 0; str[i] != '\0'; i++) {
        int ch = str[i];
        if (ch > 31 && ch <= 127) {
            my_putchar(ch);
        } else {
            printoct(ch, octbase, det);
        }
    }
    det->spaces = 0;
}

void charspe(void)
{
    my_putchar('%');
}

int bef_space(char *str)
{
    int res = 0;

    res = my_getnbr(str);
    return (res);
}
