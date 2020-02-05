/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_str_isalphanum
*/

int my_str_isalphanum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '_')
            continue;
        if ((str[i] < '0' || str[i] > '9') &&
            (str[i] < 'A' || str[i] > 'Z') &&
            (str[i] < 'a' || str[i] > 'z'))
            return 0;
    }
    return 1;
}
