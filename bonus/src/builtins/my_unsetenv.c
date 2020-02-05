/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_unsetenv
*/

#include <stdlib.h>
#include "my.h"
#include "word_array.h"
#include "get_env_path.h"

int my_unsetenv(int ac, char **av, char ***env)
{
    int line = 0;
    int nb_env_var = 0;

    if (ac == 1)
        my_putstr("unsetenv: Too few arguments.\n");
    for (int ac = 1; av[ac] != NULL; ac++) {
        nb_env_var = word_array_len(*env);
        line = getline_env_value(*env, av[ac]);
        if (line != -1) {
            free((*env)[line]);
            (*env)[line] = NULL;
            (*env)[line] = (*env)[nb_env_var - 1];
            (*env)[nb_env_var - 1] = NULL;
        }
    }
    return 0;
}