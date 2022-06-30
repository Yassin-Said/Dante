/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** display a number
*/

void my_putchar(char c);

int isneg(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    return (nb);
}

int my_put_nbr(int nb)
{
    int inc = 0;

    inc = 1;
    nb = isneg(nb);
    while (nb / inc >= 10)
        inc = inc * 10;
    while (inc != 0) {
        my_putchar((nb / inc) + 48);
        nb = nb % inc;
        inc = inc / 10;
    }
    return (0);
}
