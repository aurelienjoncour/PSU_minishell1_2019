/*
** EPITECH PROJECT, 2019
** my_str_isalpha
** File description:
** return 1 if the str only countain alphabetical characters
*/

int my_strlen(char const *str);

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (i < my_strlen(str)) {
        if ((str[i] < 'A' || str[i] > 'Z') && (str [i] < 'a' || str[i] > 'z'))
            return (0);
        i++;
    }
    return (1);
}
