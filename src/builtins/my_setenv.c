/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_setenv
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "builtins.h"
#include "word_array.h"
#include "get_env_path.h"
#include "error.h"
#include "my.h"

static bool error_handling(int ac, char **av, char ***env)
{
    if (ac == 1) {
        my_env(ac, av, env);
        return true;
    }
    if (ac > 3) {
        my_putstr(TOO_ARG);
        return true;
    }
    if (!my_char_isalpha(av[1][0])) {
        my_putstr(BAD_1_CHAR);
        return true;
    }
    if (!my_str_isalphanum(av[1])) {
        my_putstr(BAD_NAME);
        return true;
    }
    return false;
}

static int create_env_var(char ***env, char *var_env)
{
    char **new_env = NULL;
    int len = word_array_len(*env);

    new_env = word_array_realloc(*env);
    new_env[len] = var_env;
    free_2d_array(*env);
    *env = new_env;
    return 0;
}

static int set_env_var(char ***env, char *var_env, char *var_name)
{
    int j = 0;

    j = getline_env_value(*env, var_name);
    free((*env)[j]);
    (*env)[j] = var_env;
    return 0;
}

static int one_argument(char ***env, char *var_env, char *var_name)
{
    if (getline_env_value(*env, var_env) == -1)
        create_env_var(env, var_env);
    else
        set_env_var(env, var_env, var_name);
    return 0;
}

int my_setenv(int ac, char **av, char ***env)
{
    char *var_env;

    if (error_handling(ac, av, env))
        return 1;
    var_env = my_strcat(my_strdup(av[1]), "=");
    if (ac == 2)
        one_argument(env, var_env, av[1]);
    if (ac == 3) {
        if (getline_env_value(*env, var_env) == -1) {
            var_env = my_strcat(var_env, av[2]);
            create_env_var(env, var_env);
        } else {
            var_env = my_strcat(var_env, av[2]);
            set_env_var(env, var_env, av[1]);
        }
    }
    return 0;
}
