/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** test_gnl
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

Test(gnl, read_one_line)
{
    int fd = open("src/test_gnl.c", O_RDONLY);
    char *str;

    if (fd != -1)
        str = get_next_line(fd);
    cr_assert_str_eq(str, "/*");
    free(str);
    str = get_next_line(fd);
    cr_assert_str_eq(str, "** EPITECH PROJECT, 2020");
    free(str);
    close(fd);
}

Test(gnl, read_empty_line)
{
    int fd = open("empty_line", O_RDONLY);
    char *str;

    if (fd != -1)
        str = get_next_line(fd);
    cr_assert_null(str);
    free(str);
}

Test(gnl, one_line)
{
    int fd = open("one_line", O_RDONLY);
    char *str;

    if (fd != -1)
        str = get_next_line(fd);
    cr_assert_str_eq(str, "lol");
    free(str);
}

Test(gnl, invalid_fd)
{
    int fd = -1;
    char *str;

    str = get_next_line(fd);
    cr_assert_null(str);
}