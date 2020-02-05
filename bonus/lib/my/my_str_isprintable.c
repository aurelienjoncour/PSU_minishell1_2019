/*
** EPITECH PROJECT, 2019
** my_str_isprintable.c
** File description:
** returns 1 if the string passed as parameters only contanis printable char
*/

int my_strlen(char const *str);

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (i < my_strlen(str)) {
        if (str[i] < 32 || str[i] > 126)
            return (0);
        i++;
    }
    return (1);
}
