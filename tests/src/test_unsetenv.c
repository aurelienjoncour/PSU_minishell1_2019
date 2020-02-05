/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** test_unsetenv
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "builtins.h"
#include <string.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(unsetenv, error, .init = redirect_all_std)
{
    char **env = malloc(sizeof(char *) * 2);
    char **av = malloc(sizeof(char *) * 2);

    env[0] = strdup("lol=mdr");
    env[1] = NULL;
    av[0] = strdup("unsetenv");
    av[1] = NULL;
    my_unsetenv(1, av, &env);
    cr_assert_stdout_eq_str("unsetenv: Too few arguments.\n");
    for (int i = 0; env[i] != NULL; i++)
        free(env[i]);
    for (int i = 0; av[i] != NULL; i++)
        free(av[i]);
    free(env);
    free(av);
}

Test(unsetenv, no_error)
{
    char **env = malloc(sizeof(char *) * 2);
    char **av = malloc(sizeof(char *) * 3);

    env[0] = strdup("lol=mdr");
    env[1] = NULL;
    av[0] = strdup("unsetenv");
    av[1] = strdup("lol");
    av[2] = NULL;
    my_unsetenv(1, av, &env);
    cr_assert_null(env[0]);
    for (int i = 0; env[i] != NULL; i++)
        free(env[i]);
    for (int i = 0; av[i] != NULL; i++)
        free(av[i]);
    free(env);
    free(av);
}

Test(unsetenv, error_no_var)
{
    char **env = malloc(sizeof(char *) * 2);
    char **av = malloc(sizeof(char *) * 3);

    env[0] = strdup("lol=mdr");
    env[1] = NULL;
    av[0] = strdup("unsetenv");
    av[1] = strdup("mdr");
    av[2] = NULL;
    my_unsetenv(1, av, &env);
    cr_assert_str_eq(env[0], "lol=mdr");
    for (int i = 0; env[i] != NULL; i++)
        free(env[i]);
    for (int i = 0; av[i] != NULL; i++)
        free(av[i]);
    free(env);
    free(av);
}