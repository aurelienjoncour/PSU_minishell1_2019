/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_char_is_alpha
*/

#include <stdbool.h>

bool my_char_isalpha(char c)
{
    if (c == '_')
        return true;
    if (c >= 'A' && c <= 'Z')
        return true;
    else if (c >= 'a' && c <= 'z')
        return true;
    else
        return false;
}