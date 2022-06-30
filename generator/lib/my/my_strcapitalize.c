/*
** EPITECH PROJECT, 2021
** my_strcapitalize
** File description:
** capitalized first letter of each word
*/

char *conditions(char *str, int i)
{
    if (str[i - 1] == ' ' || str[i - 1] == '-') {
        str[i] = str[i] - 32;
    }
    return (str);
}

char *condition2(char *str, int i)
{
    if (str [i - 1] != ' ' || str[i - 1] == '-') {
        str[i] = str[i] + 32;
    }
    return (str);
}

void all_condition(char *str, int i)
{
    if (i == 0 && str[i] < 123 && str[i] > 96)
        str[i] = str[i] - 32;
    else if (str[i] < 123 && str[i] > 96)
        str = (conditions(str, i));
}

char *my_strcapitalize(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        all_condition(str, i);
        i++;
    }
    return (str);
}
