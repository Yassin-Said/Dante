/*
** EPITECH PROJECT, 2021
** my_compute_power_root
** File description:
** return the square root of a number gived
*/

int my_compute_power_rec(int nb, int p);

int my_compute_square_root(int nb)
{
    int res;
    int incr;

    incr = 1;
    res = 0;
    if (nb <= 0)
        return (0);
    while (res != nb) {
        res = my_compute_power_rec(incr, 2);
        if (res > nb)
            return (0);
        incr = incr + 1;
    }
    return (incr - 1);
}
