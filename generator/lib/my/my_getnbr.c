/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** find a number on a string
*/

int count_sign(char *str, int res)
{
    int count_n = 0;
    int k = 0;

    while (str[k] != '\0') {
        if (str[k] == '-') {
            count_n = count_n + 1;
        }
        k = k + 1;
    }
    if ((count_n % 2) == 1) {
        return (res * (-1));
    }
    return (res);
}

int my_getnbr(char *str)
{
    int i = 0;
    long long res = 0;

    while (str[i] == '+' || str[i] == '-') {
        i = i + 1;
    }
    while (str[i] > 47 && str[i] < 58) {
        res = (res * 10) + (str[i] - 48);
        if (res > 2147483647) {
            return (0);
        }
        i = i + 1;
    }
    return (count_sign(str, res));
}
