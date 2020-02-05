/*
** EPITECH PROJECT, 2019
** my_str_islower
** File description:
** return 1 if the string only contains lower alphabetical char
*/

int my_strlen(char const *str);

int my_str_islower(char const *str)
{
    int i = 0;

    while (i < my_strlen(str)) {
        if (str[i] < 'a' || str[i] > 'z')
            return (0);
        i++;
    }
    return (1);
}
