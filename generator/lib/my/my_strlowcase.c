/*
** EPITECH PROJECT, 2021
** my_strlowcase
** File description:
** put every letter on lower cases
*/

char *my_strlowcase(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        if (str[i] < 91 && str[i] > 64)
            str[i] = str[i] + 32;
        i++;
    }
    return (str);
}
