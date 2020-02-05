/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** return 1 if the string is only contains digits
*/

int my_strlen(char const *str);

int my_str_isnum(char const *str)
{
    int i = 0;

    while (i < my_strlen(str)) {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}
