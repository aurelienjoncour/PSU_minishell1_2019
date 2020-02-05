/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_cd_error
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my.h"

void put_error_cd(char *path)
{
    struct stat buf;

    my_putstr(path);
    if (stat(path, &buf) == -1) {
        my_putstr(": No such file or directory.\n");
        return;
    }
    if (!S_ISDIR(buf.st_mode)) {
        my_putstr(": Not a directory.\n");
        return;
    }
    if (access(path, X_OK) == -1 && access(path, F_OK) == 0) {
        my_putstr(": Permission denied.\n");
        return;
    }
}