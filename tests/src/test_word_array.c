/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** test_word_array
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include "word_array.h"

Test(word_array_len, simple_test)
{
    char **av = malloc(sizeof(char * ) * 5);

    av[0] = strdup("Lol");
    av[1] = strdup("mdr");
    av[2] = strdup("ok!");
    av[3] = strdup("yes");
    av[4] = NULL;
    cr_assert_eq(word_array_len(av), 4);
    for (int i = 0; av[i] != NULL; i++)
        free(av[i]);
    free(av);
}

Test(word_array_dup, simple_test)
{
    char **av = malloc(sizeof(char *) * 2);
    char **dup;

    av[0] = strdup("lol=mdr");
    av[1] = NULL;
    dup = word_array_dup(av);
    cr_assert_str_eq(dup[0], "lol=mdr");
    cr_assert_null(dup[1]);
    for (int i = 0; av[i] != NULL; i++) {
        free(av[i]);
        free(dup[i]);
    }
    free(av);
    free(dup);
}

Test(word_array_realloc, simple_test)
{
    char **av = malloc(sizeof(char * ) * 2);
    char **dup;

    av[0] = strdup("lol=mdr");
    av[1] = NULL;
    dup = word_array_realloc(av);

    cr_assert_null(av[2]);
    free(av[0]);
    free(dup[0]);
    free(av);
    free(dup);
}