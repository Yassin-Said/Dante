/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** display a string
*/

#include "my.h"
#include <unistd.h>

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}
