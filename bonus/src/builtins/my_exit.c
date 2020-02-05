/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_exit
*/

#include <stdlib.h>
#include "my.h"
#include "word_array.h"

char my_exit(char **av, char **env_dup, char *str)
{
    unsigned char value = 0;

    my_putstr("exit\n");
    if (word_array_len(av) < 2)
        value = 0;
    else
        value = my_getnbr(av[1]);
    free(str);
    free_2d_array(av);
    free_2d_array(env_dup);
    return value;
}