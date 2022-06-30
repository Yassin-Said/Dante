/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** swap two int
*/

void my_swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
