/*
** EPITECH PROJECT, 2019
** my_str_isupper.c
** File description:
** return 1 if the string onlyy contains upper alphabetical char
*/

int my_strlen(char const *str);

int my_str_isupper(char const *str)
{
    int i = 0;

    while (i < my_strlen(str)) {
        if (str[i] < 'A' || str[i] > 'Z')
            return (0);
        i++;
    }
    return (1);
}
