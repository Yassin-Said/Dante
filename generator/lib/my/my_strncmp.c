/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** is two char equal
*/

int my_strlen(char const *str);

int compare2(char const *s1, char const *s2, int n)
{
    int incr;

    for (incr = 0; incr != n; incr++) {
        if (s1[incr] < s2[incr])
            return (-1);
        else if (s1[incr] > s2[incr])
            return (1);
    }
    return (0);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int len1;
    int len2;

    len1 = my_strlen(s1);
    len2 = my_strlen(s2);
    if (len1 >= n && len2 >= n)
        return (compare2(s1, s2, n));
    else if (len1 < n)
        return (1);
    else
        return (-1);
}
