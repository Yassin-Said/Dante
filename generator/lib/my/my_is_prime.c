/*
** EPITECH PROJECT, 2021
** is prime
** File description:
** is the input number a prime number
*/

int my_is_prime(int nb)
{
    int incr;

    if (nb < 2)
        return (0);
    for (incr = nb - 1; incr != 1; incr--) {
        if (nb % incr == 0)
            return (1);
    }
    return (0);
}
