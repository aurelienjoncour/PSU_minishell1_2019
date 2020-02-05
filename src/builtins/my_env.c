/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_env
*/

#include <stdlib.h>
#include "my.h"
#include "word_array.h"

int my_env(int ac, char **av, char ***env)
{
    if (ac > 1) {
        my_putstr("env: ‘");
        my_putstr(av[1]);
        my_putstr("’: No such file or directory\n");
        return 1;
    }
    for (size_t i = 0; (*env)[i] != NULL; i++) {
        my_putstr((*env)[i]);
        my_putstr("\n");
    }
    return 0;
}