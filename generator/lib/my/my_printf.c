/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** display anything no matter the type
*/

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include "printf.h"

void my_putb(va_list list, struct detail *det)
{
    int nbr = 0;

    struct flag2 all_base[] = {
        {'x', &my_putbase, "0123456789abcdef\0", "0x\0"},
        {'b', &my_putbase, "01\0", "0\0"},
        {'X', &my_putbase, "0123456789ABCDEF\0", "0X\0"},
        {'o', &my_putbase, "01234567\0", "\0"}
    };
    for (int i = 0; i != 4; i++) {
        if (all_base[i].c == det->c) {
            nbr = va_arg(list, long unsigned int);
            all_base[i].fonct(nbr, all_base[i].base, det, all_base[i].ext);
        }
    }
    det->spaces = 0;
}

void my_nbr(va_list list, struct detail *det)
{
    int nbr = va_arg(list, int);

    display_all_nbr(det, nbr);
}

int call_disp(int *incr, va_list list, struct detail det)
{
    struct flag {
        char fl;
        void (*fonct)(va_list, struct detail *);
    };
    struct flag all_flag[] = {
        {'s', &my_puts}, {'S', &my_putss}, {'d', &my_nbr}, {'c', &my_putc},
        {'b', &my_putb}, {'x', &my_putb}, {'u', &my_putu}, {'X', &my_putb},
        {'C', &my_putc}, {'i', &my_nbr}, {'o', &my_putb}
    };
    for (int i = 0; i != 12; i++) {
        if (all_flag[i].fl == det.str[*incr + 1]) {
            det.c = all_flag[i].fl;
            all_flag[i].fonct(list, &det);
        }
    }
    return (0);
}

void ishtg(struct detail *det)
{
    if (det->str[*det->index + 1] == '#') {
        det->htg = 1;
        *det->index = *det->index + 1;
    }
}

int my_printf(const char *format, ...)
{
    va_list list;
    struct detail det = {' ', 0, format, 0, 0, 0};

    va_start(list, format);
    for (int i = 0; format[i] != '\0' && i < my_strlen(format); i = i + 2) {
        det.index = &i;
        if (format[i] != '%') {
            my_putchar(format[i]);
            i--;
        } else if (format[i + 1] == '%') {
            my_putchar('%');
        } else {
            ishtg(&det);
            det.spaces = format_nbr(format, &i);
            is_point(&det);
            call_disp(&i, list, det);
        }
    }
    va_end(list);
    return (0);
}
