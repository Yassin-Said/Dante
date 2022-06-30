/*
** EPITECH PROJECT, 2021
** my_strncpy
** File description:
** copy up to n
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int incr;

    for (incr = 0; incr != n; incr++) {
        if (src[incr] == '\0') {
            dest[incr] = '\0';
            return (dest);
        }
        dest[incr] = src[incr];
    }
    dest[incr] = '\0';
    return (dest);
}
