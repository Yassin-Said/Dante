/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** is two char equal
*/

int my_strlen(char const *str);

int compare(char const *s1, char const *s2)
{
    int len;
    int incr;

    len = my_strlen(s1);
    for (incr = 0; incr != len; incr++) {
        if (s1[incr] < s2[incr])
            return (-1);
        else if (s1[incr] > s2[incr])
            return (1);
    }
    return (0);
}

int my_strcmp(char const *s1, char const *s2)
{
    int len1;
    int len2;

    len1 = my_strlen(s1);
    len2 = my_strlen(s2);
    if (len1 == len2) {
        return (compare(s1, s2));
    } else if (len1 < len2) {
        return (1);
    }
    return (-1);
}
