/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** test_getenvpath
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include "get_env_path.h"

Test(get_env_path, no_path_variable)
{
    char **env = malloc(sizeof(char *)* 2);
    char **env_path;

    env[0] = strdup("PTH=");
    env[1] = NULL;
    env_path = get_env_path(env);
    cr_assert_null(env_path);
}

Test(get_env_path, no_error)
{
    char **env = malloc(sizeof(char *) * 2);
    char **env_path;

    env[0] = strdup("PATH=usr/bin/lol:mdr/trop:/home/aurelien.joncour");
    env[1] = NULL;
    env_path = get_env_path(env);
    cr_assert_str_eq(env_path[0], "usr/bin/lol");
    cr_assert_str_eq(env_path[1], "mdr/trop");
    cr_assert_str_eq(env_path[2], "/home/aurelien.joncour");
    cr_assert_null(env_path[3]);
}