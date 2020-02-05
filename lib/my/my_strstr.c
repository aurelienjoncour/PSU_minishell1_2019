/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** return a pointer at the begining of the occurence
*/
#include <stdio.h>
#include <stddef.h>

int my_strlen(char const *str);

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;

    while (i < my_strlen(str)) {
        if (str[i] == to_find[j])
            j++;
        else
            j = 0;
        i++;
        if (j == my_strlen(to_find) - 1 && my_strlen(to_find)) {
            return (&str[i]);
        }
    }
    return 0;
}
