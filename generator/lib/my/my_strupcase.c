/*
** EPITECH PROJECT, 2021
** my_strupcase
** File description:
** put every letter in upper case
*/

char *my_strupcase(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        if (str[i] > 96 && str[i] < 123) {
            str[i] = str[i] - 32;
        }
        i++;
    }
    return (str);
}
