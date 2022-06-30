/*
** EPITECH PROJECT, 2021
** my_find_prime_sup
** File description:
** find the most near prime number equal or superior
*/

int my_is_prime(int);

int my_find_prime_sup(int nb)
{
    int incr;
    int res;

    incr = nb;
    res = 0;
    if (nb < 0)
        return (0);
    while (res != 1) {
        res = my_is_prime(incr);
        incr = incr + 1;
    }
    return (incr - 1);
}
