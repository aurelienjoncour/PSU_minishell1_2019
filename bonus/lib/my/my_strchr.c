/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_strchr
*/

#include <stdlib.h>

int my_strchr(const char *str, char c)
{
    for (size_t i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return 1;
    return 0;
}